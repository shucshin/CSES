#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

vector<vi> AL;
vi dst_s, dst_t;
int max_dist = 0;
int farthest_node = 0;
 
void dfs(int u, int parent, int dist) {
    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = u;
    }
    for (auto &v : AL[u]) {
        if (v != parent) dfs(v, u, dist + 1);
    }
}
 
void dfs2(ll u, ll p, ll s) {
    if(s == 1) dst_s[u] = dst_s[p] + 1;
    if(s == 2) dst_t[u] = dst_t[p] + 1;
    for(auto &v : AL[u]) {
        if(v != p) dfs2(v, u, s);
    }
}
 
void solve() {
    ll n; cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
 
    AL.assign(n+1, {});
    dst_s.assign(n+1,0);
    dst_t.assign(n+1,0);
    FOR(i,0,n-1) {
        ll a, b; cin >> a >> b;
        AL[a].pb(b); AL[b].pb(a);
    }
    dfs(1, 0, 0);
    dfs2(farthest_node, 0, 1); 
    max_dist = 0;
    dfs(farthest_node, 0, 0);
    dfs2(farthest_node, 0, 2);
 
    FOR(u,1,n+1) {
        cout << max(dst_s[u], dst_t[u])-1 << " ";
    }   cout << endl;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}