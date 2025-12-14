#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
 
class SCC {
private:
    vector<vi> AL, rAL, cAL;
    vi vis, S, cmp;
    ll MXN, cmp_cnt = 1;
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
    
    vi Kosaraju() {
        FOR(u,0,MXN) { if(!vis[u]) dfs(u); }
        RFOR(i,0,MXN) {
            ll u = S[i];
            if(cmp[u] < 0) dfs2(u), cmp_cnt++; 
        }
		return cmp;
    }
 
	ll components() { return cmp_cnt-1; }
};
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, u, v; cin >> n >> m;
	SCC scc(n);
	FOR(_,0,m) {
		cin >> u >> v; --u, --v;
		scc.addEdge(u,v);
	}
	vi cmp = scc.Kosaraju();
 
	cout << scc.components() << endl;
	FOR(u,0,n) cout << cmp[u] << " "; cout << endl;
 
	return 0;
}