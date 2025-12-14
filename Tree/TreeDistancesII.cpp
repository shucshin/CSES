#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vector<vi> AL; 
vi sub, dp, ans;
 
void dfs_down(ll u, ll p) {
    sub[u] = 1; dp[u] = 0;
    for(auto &v : AL[u]) if(v != p) {
        dfs_down(v, u);
        sub[u] += sub[v];
        dp[u]  += dp[v] + sub[v]; 
    }
}
 
void dfs_up(ll u, ll p, ll n) {
    for(auto &v : AL[u]) if(v != p) {
        ans[v] = ans[u] + (n - 2*sub[v]);
        dfs_up(v, u, n);
    }
}
 
void solve() {
    ll n; cin >> n;
    AL.assign(n+1, {});
    sub.assign(n+1, 0);
    dp.assign(n+1, 0);
    ans.assign(n+1, 0);
    FOR(i,0,n-1) {
        ll a, b; cin >> a >> b;
        AL[a].pb(b); AL[b].pb(a);
    }
 
    dfs_down(1, 0);
    ans[1] = dp[1];
    dfs_up(1, 0, n);
 
    FOR(u,1,n+1) cout << ans[u] << (u==n? '\n' : ' ');
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}