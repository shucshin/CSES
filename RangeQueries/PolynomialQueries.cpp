#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
class Lazy {
private:
struct node {ll x = 0, la = 0, lb = 0; bool hl = 0; node(){};};
    ll l(ll p) {return (p << 1);} 
    ll r(ll p) {return (p << 1) + 1;}
 
    ll sumI(ll L, ll R) { // sum of indices L..R
        return (R * (R + 1) / 2) - ((L - 1) * L / 2);
    }
 
    void merge(ll p) {
        st[p].x = st[l(p)].x + st[r(p)].x;
    }
 
    void build(ll p, ll L, ll R) {
        if(L == R) {st[p].x = A[L]; return;}
        ll m = (L + R) >> 1;
        build(l(p), L, m); // left segment
        build(r(p),m+1,R); // right segment
        merge(p);          // merge
    }
 
    void apply(ll p, ll L, ll R, ll a, ll b) { // apply A[i] += a*i + b on [L,R]
        st[p].x  += a * sumI(L,R) + b * (R - L + 1);
        st[p].la += a;
        st[p].lb += b;
        st[p].hl  = 1;
    }
 
    void push(ll p, ll L, ll R) { // Lazy Propagation
        if(!st[p].hl || L == R) return;
        ll m = (L + R) >> 1;
        apply(l(p), L,   m, st[p].la, st[p].lb);
        apply(r(p), m+1, R, st[p].la, st[p].lb);
        st[p].la = 0; st[p].lb = 0; st[p].hl = 0;
    }
 
    void upd(ll p, ll L, ll R, ll i, ll j, ll a, ll b) { 
        if(i >  R || j <  L) return;  // out-bound
        if(i <= L && R <= j) {        //  in-bound
            apply(p, L, R, a, b);
            return;
        }
        ll m = (L + R) >> 1;
        push(p, L, R);
        upd(l(p), L, m, i, j, a, b);
        upd(r(p),m+1,R, i, j, a, b);
        merge(p);
    }
 
    ll query(ll p, ll L, ll R, ll i, ll j) {
        if(i >  R || j <  L)  return 0;         // out-bound
        if(i <= L && R <= j)  return st[p].x;   //  in-bound
        ll m = (L + R) >> 1;
        push(p, L, R);
        return query(l(p),  L,  m, i, j)
             + query(r(p), m+1, R, i, j);
    }
 
public:
    ll n; vi A; vector<node> st;
    Lazy(ll sz) : n(sz), A(n+1), st(4*n+5) {}
    void build() {build(1, 1, n);} 
    // increase A[i] by (i - a + 1) for i in [a,b]
    void add_ap(ll a, ll b) { upd(1, 1, n, a, b, 1, 1 - a); }
    void upd(ll i, ll j, ll da, ll db) {upd(1, 1, n, i, j, da, db);} 
    ll query(ll i, ll j) {return query(1, 1, n, i, j);} 
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    Lazy st(n);
    FOR(i,1,n+1) cin >> st.A[i];
    st.build();
    while(q--) {
        ll t, a, b; cin >> t >> a >> b;
        if(t == 1) {
            st.add_ap(a, b);
        } else {
            cout << st.query(a, b) << endl;
        }
    }
    return 0;
}