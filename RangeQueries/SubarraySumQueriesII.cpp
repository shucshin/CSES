#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
class Segtree {
private:
struct node {ll x = 0, pfx = 0, sfx = 0, ans = 0; node(){};};
    ll l(ll p) {return (p << 1);}
    ll r(ll p) {return (p << 1) + 1;}
   
    void merge(ll p) {
        st[p].x = st[l(p)].x + st[r(p)].x;
        st[p].pfx = max(st[l(p)].pfx, st[l(p)].x + st[r(p)].pfx);
        st[p].sfx = max(st[r(p)].sfx, st[r(p)].x + st[l(p)].sfx);
        st[p].ans = max(max(st[l(p)].ans, st[r(p)].ans)
                        ,st[l(p)].sfx + st[r(p)].pfx);
    }
    
    void build(ll p, ll L, ll R) {
        if(L == R) {
            st[p].x = A[L]; 
            st[p].pfx = st[p].sfx = st[p].ans = max(0ll, A[L]);
            return;
        }
        ll m = (L + R) >> 1;
        build(l(p), L, m); // left segment
        build(r(p),m+1,R); // right segment
        merge(p);          // merge
    }
 
    node combine(node a, node b) {
        node n;
        n.x   = a.x + b.x;
        n.pfx = max(a.pfx, a.x + b.pfx);
        n.sfx = max(b.sfx, b.x + a.sfx);
        n.ans = max(max(a.ans, b.ans)
                    ,a.sfx + b.pfx);
        return n;
    }
 
    void upd(ll p, ll L, ll R, ll i, ll val) {
        if(i >  R || i <  L) return;                  // out-bound
        if(i <= L && R <= i) {
            st[p].x = val; 
            st[p].pfx = st[p].sfx = st[p].ans = max(0ll, st[p].x);
            return;
        } //  in-bound
        ll m = (L + R) >> 1;
        if(i <= m) upd(l(p), L, m,i,val);
        else       upd(r(p),m+1,R,i,val);
        merge(p);
    }
 
    node query(ll p, ll L, ll R, ll i, ll j) {
        if(i >  R || j <  L)  return {};      // out-bound
        if(i <= L && R <= j)  return st[p];   //  in-bound
        ll m = (L + R) >> 1;
        return combine(query(l(p),  L,  m, i, j),
                       query(r(p), m+1, R, i, j));
    }
    
public:
    ll n; vi A; vector<node> st;
    Segtree(ll sz) : n(sz), A(n+1), st(4*n+5) {}
    void build() {build(1, 1, n);}
    void upd(ll i, ll val) {upd(1, 1, n, i, val);}
    ll query(ll i, ll j) {return query(1, 1, n, i, j).ans;}
    // For 0-indexed do (1, 0, n-1) for all first 3 args 
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    Segtree st(n);
    FOR(i,1,n+1) cin >> st.A[i];
    st.build();
 
    while(q--) {
        ll a, b; cin >> a >> b;
        cout << st.query(a, b) << endl;
    }
    return 0;
}