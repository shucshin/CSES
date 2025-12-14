#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vector<vi> AL; 
vi dp0, dp1;
 
void dfs(ll u, ll p) {
    ll base = 0;
    for(auto &v : AL[u]) if(v != p) {
        dfs(v, u);
        base += max(dp0[v], dp1[v]);
    }
    dp0[u] = base;
    ll best_add = 0;
    for(auto &v : AL[u]) if(v != p) {
        best_add = max(best_add, 1 + dp0[v] - max(dp0[v], dp1[v]));
    }
    dp1[u] = base + best_add;
}
 
void solve() {
    ll n; cin >> n;
    AL.assign(n+1, {});
    dp0.assign(n+1, 0); dp1.assign(n+1, 0);
    FOR(i,0,n-1) {
        ll a, b; cin >> a >> b;
        AL[a].pb(b); AL[b].pb(a);
    }
    dfs(1, 0);
    cout << max(dp0[1], dp1[1]) << endl;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}