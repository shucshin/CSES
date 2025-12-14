#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll MOD = 1e9+7;

ll n, dp[1 << 20][20]; // MXN causes RTE
vector<vi> AL;

/**== Idea ==
 * Use bitmask to keep track of visited nodes. 0 visited, 1 unvisited
 * If reach node n mask is 0, then it's a valid path.
 */

ll dfs(ll mask, ll u) {
    mask ^=  (1 << u); // visit node by flipping to 0 with XOR
    if(u == n-1 && !mask) return 1;
    if(u == n-1)          return 0; // path has unvisited nodes
    if(dp[mask][u] != -1) return dp[mask][u];

    ll res = 0;
    for(auto v : AL[u]) {
        if((1 << v) & mask) { // node v is unvisited yet
            (res += dfs(mask,v)) %= MOD;
        }
    }
    return dp[mask][u] = res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll m, u, v; cin >> n >> m; AL.assign(n,{});
    FOR(_,0,m) {
        cin >> u >> v; --u; --v;
        AL[u].pb(v);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs((1 << n) - 1, 0) << endl;
    return 0;
}