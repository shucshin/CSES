#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vector<vi> AL; vi subtree;
ll n;
 
void dfs(ll u, ll p) {
    subtree[u] = 1;
    for(auto &v : AL[u]) if(v != p) {
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}
 
ll centroid(ll u, ll p) {
    for(auto &v : AL[u]) if(v != p && subtree[v]*2 > n) {
        // >= n for other centroid
        return centroid(v, u);
    } return u;
}
 
void solve(){
    cin >> n;
    AL.assign(n+1, {});
    FOR(_,0,n-1){ ll a,b; cin >> a >> b; AL[a].pb(b); AL[b].pb(a); }
    subtree.assign(n+1, 0);
    dfs(1, 0);
    cout << centroid(1, 0) << endl;
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}