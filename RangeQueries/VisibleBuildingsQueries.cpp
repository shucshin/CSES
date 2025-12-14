#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
 
#define LSOne(a) ((a) & -(a))
struct Fenwick {
    ll n; vi bit; // Binary Indexed Tree
    Fenwick(ll N): n(N), bit(n+1, 0) {}
    void add(ll i, ll v) {
        for(; i <= n; i += LSOne(i)) bit[i] += v;
    }
    ll query(ll i) {
        ll sum = 0;
        for(; i > 0; i -= LSOne(i)) sum += bit[i];
        return sum;
    }
    ll query(ll l, ll r) { return query(r) - query(l-1); }
};
 
struct qry { ll a, b, id; };
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vi h(n+1); FOR(i,1,n+1) cin >> h[i];
 
    // L[i] - index on left  of nearest element >= h[i]
    vi L(n+1, 0); 
    stack<ll> stk;
    RFOR(i,1,n+1) {
        while(!stk.empty() && h[i] >= h[stk.top()]) {
            L[stk.top()] = i;
              stk.pop();
        }     stk.push(i);
    }
 
    vector<qry> qs(q);
    FOR(i,0,q) { 
        ll a, b; cin >> a >> b; 
        qs[i] = {a,b,i}; 
    }
    sort(all(qs), [&](const qry &x, const qry &y) { 
        return x.a < y.a; 
    });
 
    vi ord(n); FOR(i,0,n) ord[i] = i+1;
    sort(all(ord), [&](ll i, ll j){ return L[i] < L[j]; });
 
    Fenwick ft(n);
    vi ans(q, 0);
    ll k = 0;
    for(auto &[a,b,id] : qs) {
        while(k < n && L[ord[k]] < a) { ft.add(ord[k], 1); k++; }
        ans[id] = ft.query(a, b);
    }
 
    FOR(i,0,q) cout << ans[i] << endl;
    return 0;
}