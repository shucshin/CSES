#include <bits/stdc++.h>
using namespace std;
using ll = long long;   // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define  FOR(i,a,b) for(int i = (a);   i <  (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define  all(a) (a).begin() , (a).end()
#define rall(a) (a).rbegin(), (a).rend()
const ll MOD = 1e9+7; // 998244353
const ll MXN = 2e5+5;
const ll INF = 1e18;
 
// Segment Tree
class Segtree {
private:
struct node {ll x=0, pfx=0; node(){};};
    ll l(ll p) {return (p << 1);}
    ll r(ll p) {return (p << 1)+1;}
    void merge(ll p) {
        st[p].x = st[l(p)].x + st[r(p)].x;
        st[p].pfx = max(st[l(p)].pfx, st[l(p)].x+st[r(p)].pfx);
    }
 
    node combine(node a, node b) {
        node n;
        n.x   = a.x+b.x;
        n.pfx = max(a.pfx, a.x+b.pfx);
        return n;
    }
 
    void build(ll p, ll L, ll R) {
        if(L == R) {st[p].x = A[L]; 
                    st[p].pfx = max(0ll,A[L]);
                    return;
                   }
        ll m = (L+R) >> 1;
        build(l(p), L, m); // left segment
        build(r(p),m+1,R); // right segment
        merge(p);          // merge
    }
 
    void upd(ll p, ll L, ll R, ll i, ll val) {
        if(i >  R || i <  L) return;                  // out-bound
        if(i <= L && R <= i) {st[p].x = val; 
                              st[p].pfx = max(0ll,val);
                              return;
                             } //  in-bound
        ll m = (L+R) >> 1;
        if(i <= m) upd(l(p), L, m,i,val);
        else       upd(r(p),m+1,R,i,val);
        merge(p);
    }
 
    node query(ll p, ll L, ll R, ll i, ll j) {
        if(i >  R || j <  L)  return {};      // out-bound
        if(i <= L && R <= j)  return st[p];   //  in-bound
        ll m = (L+R) >> 1;
        return combine(query(l(p),  L,  m, i, j),
                       query(r(p), m+1, R, i, j));
    }
 
    void printST() {
        FOR(i,1,4*n) {
            cout << "Node " << i << " : " << st[i].x << "\n";
        }
    }
    
public:
    ll n; vi A; vector<node> st;
    Segtree(ll sz) : n(sz), A(n+1), st(4*n+5) {}
    void build() {build(1,1,n);}
    void upd(ll i, ll val) {upd(1,1,n,i,val);}
    ll query(ll i, ll j) {return query(1,1,n,i,j).pfx;}
    void print() {printST();}
};
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q, k, a, b; cin >> n >> q;
    Segtree st(n); FOR(i,1,n+1) cin >> st.A[i]; st.build();
 
    FOR(_,0,q) {
        cin >> k >> a >> b;
        if(k == 1) {
            st.upd(a,b);
        } else {
            cout << st.query(a,b) << endl;
        }
    }
    return 0;
}