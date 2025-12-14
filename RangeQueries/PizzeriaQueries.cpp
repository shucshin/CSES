#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
class Segtree {
private:
struct node {ll x = 0; node(){};};
    ll l(ll p) {return (p << 1);}
    ll r(ll p) {return (p << 1) + 1;}
    void merge(ll p) {st[p].x = min(st[l(p)].x, st[r(p)].x);}
    void build(ll p, ll L, ll R) {
        if(L == R) {st[p].x = A[L]; return;}
        ll m = (L + R) >> 1;
        build(l(p), L, m); // left segment
        build(r(p),m+1,R); // right segment
        merge(p);          // merge
    }
 
    void upd(ll p, ll L, ll R, ll i, ll val) {
        if(i >  R || i <  L) return;                  // out-bound
        if(i <= L && R <= i) {st[p].x = val; return;} //  in-bound
        ll m = (L + R) >> 1;
        if(i <= m) upd(l(p), L, m,i,val);
        else       upd(r(p),m+1,R,i,val);
        merge(p);
    }
 
    ll query(ll p, ll L, ll R, ll i, ll j) {
        if(i >  R || j <  L)  return INF;         // out-bound
        if(i <= L && R <= j)  return st[p].x;   //  in-bound
        ll m = (L + R) >> 1;
        return min(query(l(p),  L,  m, i, j)
                 , query(r(p), m+1, R, i, j));
    }
    
public:
    ll n; vi A; vector<node> st;
    Segtree(ll sz) : n(sz), A(n+1), st(4*n+5) {}
    void build() {build(1, 1, n);}
    void upd(ll i, ll val) {upd(1, 1, n, i, val);}
    ll query(ll i, ll j) {return query(1, 1, n, i, j);}
    // For 0-indexed do (1, 0, n-1) for all first 3 args 
};
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vi p(n+1);
    FOR(i,1,n+1) cin >> p[i];
 
    Segtree st_m(n), st_p(n);
 
    FOR(i,1,n+1) {
        st_m.A[i] = p[i] - i;
        st_p.A[i] = p[i] + i;
    }
    st_m.build();
    st_p.build();
 
    while(q--) {
        ll t; cin >> t;
        if(t == 1) {
            ll k, x; cin >> k >> x;
            st_m.upd(k, x - k);
            st_p.upd(k, x + k);
        } else {
            ll k; cin >> k;
            ll L = st_m.query(1,k) + k;
            ll R = st_p.query(k,n) - k;
            cout << min(L,R) << endl;
        }
    }
 
    return 0;
}