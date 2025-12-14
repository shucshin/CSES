#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define lb(A, a) lower_bound(all(A), a) - A.begin()

const ll MOD = 1e9+7;
 
class Segtree {
private:
struct node {ll x = 0; node(){};};
    ll l(ll p) {return (p << 1);}
    ll r(ll p) {return (p << 1) + 1;}
    void merge(ll p) {st[p].x = st[l(p)].x + st[r(p)].x;}
    void build(ll p, ll L, ll R) {
        if(L == R) {st[p].x = A[L]; return;}
        ll m = (L + R) >> 1;
        build(l(p), L, m); // left segment
        build(r(p),m+1,R); // right segment
        merge(p);          // merge
    }
 
    void upd(ll p, ll L, ll R, ll i, ll val) {
        if(i >  R || i <  L) return;                  // out-bound
        if(i <= L && R <= i) {st[p].x += val; return;} //  in-bound
        ll m = (L + R) >> 1;
        if(i <= m) upd(l(p), L, m,i,val);
        else       upd(r(p),m+1,R,i,val);
        merge(p);
    }
 
    ll query(ll p, ll L, ll R, ll i, ll j) {
        if(i >  R || j <  L)  return 0;         // out-bound
        if(i <= L && R <= j)  return st[p].x;   //  in-bound
        ll m = (L + R) >> 1;
        return query(l(p),  L,  m, i, j)
             + query(r(p), m+1, R, i, j);
    }
    
public:
    ll n; vi A; vector<node> st;
    Segtree(ll sz) : n(sz), A(n+1), st(4*n+5) {}
    void build() {build(1, 0, n-1);}
    void upd(ll i, ll val) {upd(1, 0, n-1, i, val);}
    ll query(ll i, ll j) {return query(1, 0, n-1, i, j);}
};
 
ll add(ll a, ll b) { return (a + b) % MOD; }
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
 
    // Coordinate-compress
    vi v = A; sort(all(v));
    v.erase(unique(all(v)), v.end());
    // Now values have rank 0...m-1
    ll m = v.size();
    ll ans = 0;
    Segtree st(m); st.build(); // 0-indexed and st[p].x += val; for upd
    
    FOR(i,0,n) {
        ll k = lb(v, A[i]); // rank of A[i]
        ll dp = add(1, st.query(0, k-1)); // dp[0..k-1]
        ans = add(ans, dp);
        st.upd(k, dp);
    }
    cout << ans << endl;
 
    return 0;
}