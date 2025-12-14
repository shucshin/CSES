#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vector<vi> AL; vi color, ans;
vector<set<ll>> S;
 
void dfs(ll u, ll p) {
    for(auto &v : AL[u]) if(v != p) dfs(v, u);
    for(auto &v : AL[u]) if(v != p){
        if(S[u].size() < S[v].size()) S[u].swap(S[v]);
        for(auto &x : S[v]) S[u].insert(x);
        S[v].clear();
    }
    S[u].insert(color[u]);
    ans[u] = (ll)S[u].size();
}
 
void solve(){
    ll n; cin >> n;
    AL.assign(n+1, {});
    color.assign(n+1, 0);
    FOR(u,1,n+1) cin >> color[u];
    FOR(_,0,n-1){ ll a,b; cin >> a >> b; AL[a].pb(b); AL[b].pb(a); }
    ans.assign(n+1, 0); S.assign(n+1, {});
    dfs(1, 0);
    FOR(u,1,n+1) cout << ans[u] << (u==n? '\n' : ' ');
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}