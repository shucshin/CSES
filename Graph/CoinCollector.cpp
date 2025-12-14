#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
 
class SCC {
private:
    vector<vi> AL, rAL, cAL;
    vi vis, S, cmp;
    ll MXN, cmp_cnt = 0;
public:
    SCC(ll n) {
        AL.assign(n, {}); rAL.assign(n, {});
        vis.assign(n, 0);
        cmp.assign(n, -1);
        MXN = n;
    }
    void addEdge(ll u, ll v) { AL[u].pb(v); rAL[v].pb(u); }
    void dfs(ll u) {
        vis[u] = 1;
        for(auto &v : AL[u]) {
            if(!vis[v]) dfs(v); 
        }   
        S.pb(u); // post-oder list
    }
    void dfs2(ll u) { // assign component id
        cmp[u] = cmp_cnt;
        for(auto &v : rAL[u]) {
            if(cmp[v] < 0) dfs2(v);
        }
    }
    
    ll Kosaraju() {
        FOR(u,0,MXN) { if(!vis[u]) dfs(u); }
        RFOR(i,0,MXN) {
            ll u = S[i];
            if(cmp[u] < 0) dfs2(u), cmp_cnt++; 
        }
 
        cAL.assign(cmp_cnt, {}); // Condensated graph
        FOR(u,0,MXN) {
            for(auto &v : AL[u]) {
                if(cmp[u] == cmp[v]) continue;
                cAL[cmp[u]].pb(cmp[v]);
            }
        }
 
        return cmp_cnt;
    }
 
    vi& components() { return cmp; }
    vector<vi>& condensed() { return cAL; }
};
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, u, v; cin >> n >> m;
    SCC scc(n);
    vi coin(n);
    FOR(i,0,n) cin >> coin[i];
    FOR(_,0,m) {
        cin >> u >> v; --u, --v;
        scc.addEdge(u,v);
    }
    ll C = scc.Kosaraju();
 
    vi cmp_sum(C, 0); // Coin sum for each component
    vi &cmp = scc.components();
    FOR(u,0,n) {
        cmp_sum[cmp[u]] += coin[u];
    }
 
    auto &cAL = scc.condensed();
    
    vi dp(C);
    FOR(u,0,C) dp[u] = cmp_sum[u]; // Base case
    
    FOR(u,0,C) {
        for(auto &v : cAL[u]) {
            dp[v] = max(dp[v], dp[u] + cmp_sum[v]);
        }
    }
 
    cout << *max_element(all(dp)) << endl;
 
    return 0;
}