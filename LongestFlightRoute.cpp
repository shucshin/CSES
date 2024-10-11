#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
 
const ll MXN = 1e5+5;
ll n, dp[MXN], p[MXN], vis[MXN];
vector AL(MXN,vi(0));
 
ll dfs(ll u) {
    if(vis[u]) return dp[u];
    if(u == n) return dp[u] = 1;
    vis[u] = 1;
    ll res = 0;
    for(auto v : AL[u]) {
        ll x = dfs(v);
        if(x && res < x+1) {
            res = x+1;
            p[u] = v;
        }
    }
    return dp[u] = res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll m, a, b; cin >> n >> m;
    FOR(_,0,m) {
        cin >> a >> b;
        AL[a].pb(b);
    }
    dfs(1);
    
    if(!dp[1]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    cout << dp[1] << endl;
    vi A = {1}; ll x = 1;
    while(p[x] != 0) {
        A.pb(p[x]);
        x = p[x];
    }
    for(auto a : A) {
        cout << a << " "; 
    }   cout << endl;
 
    return 0;
}