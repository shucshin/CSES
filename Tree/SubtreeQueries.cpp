#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
struct Fenwick {
    ll n; vi bit;
    Fenwick() {}
    Fenwick(ll N): n(N), bit(N+1, 0) {}
    void update(ll i, ll v) { for(; i <= n; i += i & -i) bit[i] += v; }
    ll query(ll i) { ll s = 0; for(; i > 0; i -= i & -i) s += bit[i]; return s; }
    ll range_query(ll l, ll r) { return query(r) - query(l-1); }
};
 
vector<vi> AL; 
vi tin, tout, val;
ll timer_global = 0;
 
void dfs(ll u, ll p) {
    tin[u] = ++timer_global;
    for(auto &v : AL[u]) if(v != p) dfs(v, u);
    tout[u] = timer_global;
}
 
void solve() {
    ll n, q; cin >> n >> q;
    val.assign(n+1, 0);
    FOR(i,1,n+1) cin >> val[i];
    AL.assign(n+1, {});
    FOR(i,0,n-1) { ll a, b; cin >> a >> b; AL[a].pb(b); AL[b].pb(a); }
 
    tin.assign(n+1, 0); tout.assign(n+1, 0); timer_global = 0;
    dfs(1, 0);
 
    Fenwick fw(n); FOR(u,1,n+1) fw.update(tin[u], val[u]);
 
    while(q--) {
        ll type; cin >> type;
        if(type == 1) {
            ll s, x; cin >> s >> x;
            ll delta = x - val[s];
            val[s] = x;
            fw.update(tin[s], delta);
        } else {
            ll s; cin >> s;
            cout << fw.range_query(tin[s], tout[s]) << endl;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}