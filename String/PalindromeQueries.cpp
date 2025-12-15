#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 137;
 
// int code(char c){ return c - 'A' + 1; } // Uppercase
int code(char c){ return c - 'a' + 1; } // Lowercase
// int code(char c){ // Both cases
//   if('A' <= c && c <= 'Z') return c - 'A' + 1;
//   else                     return c - 'a' + 27;
// }
 
ll modpow(ll a, ll e, ll m){
    ll r = 1 % m;
    while(e){
        if(e & 1) r = (r * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return r;
}
 
struct Seg {
    int n;
    vector<ll> t1, t2;
    vector<ll> &P1, &P2, &iP1, &iP2;
    Seg(int _n,
        vector<ll>& _P1, vector<ll>& _P2,
        vector<ll>& _iP1, vector<ll>& _iP2)
      : n(_n), P1(_P1), P2(_P2), iP1(_iP1), iP2(_iP2)
    {
        t1.assign(4*n+4, 0);
        t2.assign(4*n+4, 0);
    }
    void build(int idx, int l, int r, const string &s){
        if(l == r){
            ll v = code(s[l]);
            t1[idx] = v * P1[l] % MOD1;
            t2[idx] = v * P2[l] % MOD2;
        } else {
            int m = (l + r) >> 1;
            build(idx<<1,   l,   m, s);
            build(idx<<1|1, m+1, r, s);
            t1[idx] = (t1[idx<<1] + t1[idx<<1|1]) % MOD1;
            t2[idx] = (t2[idx<<1] + t2[idx<<1|1]) % MOD2;
        }
    }
    void update(int idx, int l, int r, int pos, ll v){
        if(l == r){
            t1[idx] = v * P1[l] % MOD1;
            t2[idx] = v * P2[l] % MOD2;
        } else {
            int m = (l + r) >> 1;
            if(pos <= m) update(idx<<1,   l,   m, pos, v);
            else         update(idx<<1|1, m+1, r, pos, v);
            t1[idx] = (t1[idx<<1] + t1[idx<<1|1]) % MOD1;
            t2[idx] = (t2[idx<<1] + t2[idx<<1|1]) % MOD2;
        }
    }
    pair<ll,ll> query(int idx, int l, int r, int ql, int qr) const {
        if(qr < l || r < ql) return {0,0};
        if(ql <= l && r <= qr)
            return {t1[idx], t2[idx]};
        int m = (l + r) >> 1;
        auto L = query(idx<<1,   l,   m, ql, qr);
        auto R = query(idx<<1|1, m+1, r, ql, qr);
        return {(L.first + R.first) % MOD1,
                (L.second+ R.second)% MOD2};
    }
    // normalized hash of s[ql..qr], as if starting at exponent 0
    pair<ll,ll> get(int ql, int qr) const {
        auto h = query(1,1,n,ql,qr);
        h.first  = h.first  * iP1[ql] % MOD1;
        h.second = h.second * iP2[ql] % MOD2;
        return h;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    string S;
    cin >> S;
    S = " " + S;              // make it 1‐based
    string R = S;
    reverse(R.begin()+1, R.end());
 
    // Precompute powers and inverses
    vector<ll> P1(n+2), P2(n+2), iP1(n+2), iP2(n+2);
    P1[0] = P2[0] = 1;
    for(int i = 1; i <= n; i++){
        P1[i] = P1[i-1] * BASE % MOD1;
        P2[i] = P2[i-1] * BASE % MOD2;
    }
    ll invB1 = modpow(BASE, MOD1-2, MOD1);
    ll invB2 = modpow(BASE, MOD2-2, MOD2);
    iP1[0] = iP2[0] = 1;
    for(int i = 1; i <= n; i++){
        iP1[i] = iP1[i-1] * invB1 % MOD1;
        iP2[i] = iP2[i-1] * invB2 % MOD2;
    }
 
    // Build two segment‐trees: forward on S, forward on reversed R
    Seg segF(n, P1,P2,iP1,iP2), segR(n, P1,P2,iP1,iP2);
    segF.build(1,1,n,S);
    segR.build(1,1,n,R);
 
    auto upd = [&](int pos, char c){
        ll v = code(c);
        segF.update(1,1,n,pos,v);
        segR.update(1,1,n,n-pos+1,v);
    };
 
    auto isPal = [&](int l, int r){
        auto hF = segF.get(l, r);
        // corresponding reversed range is [n-r+1 .. n-l+1]
        auto hR = segR.get(n-r+1, n-l+1);
        return hF == hR;
    };
 
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int k; char x;
            cin >> k >> x;
            upd(k, x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << (isPal(a,b) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}