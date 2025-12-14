#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

vector<vi> AL;
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
 
void solve() {
    ll n; cin >> n;
    AL.assign(n+1, {});
    FOR(i,0,n-1) {
        ll a, b; cin >> a >> b;
        AL[a].pb(b); AL[b].pb(a);
    }
    dfs(1, 0, 0); max_dist = 0;
    dfs(farthest_node, 0, 0);
 
    cout << max_dist << endl;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}