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
 
class Segtree {
private:
struct node {ll x=0; node(){};};
    ll l(ll p) {return (p << 1);}
    ll r(ll p) {return (p << 1)+1;}
    void merge(ll p) {st[p].x = st[l(p)].x + st[r(p)].x;}
 
    void build(ll p, ll L, ll R) {
        if(L == R) {st[p].x = A[L]; return;}
        ll m = (L+R) >> 1;
        build(l(p), L, m); // left segment
        build(r(p),m+1,R); // right segment
        merge(p);          // merge
    }
 
    void upd(ll p, ll L, ll R, ll i, ll val) {
        if(i >  R || i <  L) return;                  // out-bound
        if(i <= L && R <= i) {st[p].x = val; return;} //  in-bound
        ll m = (L+R) >> 1;
        if(i <= m) upd(l(p), L, m,i,val);
        else       upd(r(p),m+1,R,i,val);
        merge(p);
    }
 
    ll query(ll p, ll L, ll R, ll i, ll j) {
        if(i >  R || j <  L)  return 0;         // out-bound
        if(i <= L && R <= j)  return st[p].x;   //  in-bound
        ll m = (L+R) >> 1;
        return query(l(p),  L,  m, i, j)
             + query(r(p), m+1, R, i, j);
    }
 
    ll kth(ll p, ll L, ll R, ll k) { // Index where prefix sum is >= k
        if(st[p].x < k) return -1;
        if(L == R)      return  L;
        ll m = (L+R) >> 1;
        if(st[l(p)].x >= k) return kth(l(p),  L,  m, k);
        else                return kth(r(p), m+1, R, k-st[l(p)].x);
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
    ll query(ll i, ll j) {return query(1,1,n,i,j);}
    ll kth(ll k) {return kth(1,1,n,k);}
    void print() {printST();}
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n;
    vi A(n+1); FOR(i,1,n+1) cin >> A[i];
    Segtree st(n); FOR(i,1,n+1) st.A[i] = 1; st.build();
    FOR(_,0,n) {
        cin >> x;
        ll k = st.kth(x);
        st.upd(k,0);
        cout << A[k] << " ";
    } cout << endl;
 
    return 0;
}