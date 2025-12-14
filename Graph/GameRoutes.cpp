#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
 
const ll MXN = 1e5+5;
const ll MOD = 1e9+7;
ll n, dp[MXN];
vector AL(MXN,vi(0));
 
ll dfs(ll u) {
    if(u == n)      return dp[u] = 1;
    if(dp[u] != -1) return dp[u];
    ll res = 0;
    for(auto v : AL[u]) {
        res = (res + dfs(v)) % MOD;
    }
    return dp[u] = res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof dp);
    ll m, a, b; cin >> n >> m;
    FOR(_,0,m) {
        cin >> a >> b;
        AL[a].pb(b);
    }
    cout << dfs(1) << endl;
    return 0;
}