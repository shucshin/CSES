#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
 
vector<vi> AL, up; 
vi depth, cnt;
ll LOGN;
 
void dfs_build(ll u, ll p) {
    up[u][0] = p;
    for(auto &v : AL[u]) if(v != p) {
        depth[v] = depth[u] + 1;
        dfs_build(v, u);
    }
}
 
ll jump(ll x, ll d) {
    FOR(i,0,LOGN) {if((d>>i)&1) x = up[x][i];} 
    return x;
}
 
ll lca(ll u, ll v) {
    if(depth[u] < depth[v]) swap(u,v);
    ll d = depth[u] - depth[v];
    u = jump(u, d);
    if(u == v) return u;
    RFOR(i,0,LOGN) if(up[u][i] != up[v][i]) {
        u = up[u][i]; v = up[v][i];
    }
    return up[u][0];
}
 
void dfs_acc(ll u, ll p) {
    for(auto &v : AL[u]) if(v != p) {
        dfs_acc(v, u);
        cnt[u] += cnt[v];
    }
}
 
void solve() {
    ll n, m; cin >> n >> m;
    AL.assign(n+1, {});
    FOR(i,0,n-1) { ll a, b; cin >> a >> b; AL[a].pb(b); AL[b].pb(a); }
 
    LOGN = 1; while((1LL << LOGN) <= n) LOGN++;
    up.assign(n+1, vi(LOGN, 0));
    depth.assign(n+1, 0);
    cnt.assign(n+1, 0);
 
    dfs_build(1, 0);
    FOR(j,1,LOGN) FOR(u,1,n+1) { ll p = up[u][j-1]; up[u][j] = up[p][j-1];} 
 
    FOR(_,0,m) { // paths
        ll a, b; cin >> a >> b;
        ll w = lca(a, b);
        cnt[a]++, cnt[b]++, cnt[w]--;
        if(up[w][0] != 0) cnt[ up[w][0] ] -= 1;
    }
 
    dfs_acc(1, 0);
 
    FOR(u,1,n+1) cout << cnt[u] << (u==n? '\n' : ' ');
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}