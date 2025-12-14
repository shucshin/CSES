#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
 
class Toposort {
private:
    vector<vi> AL; ll MXN;
    vector<ll> ts, tl, vis, deg;
    priority_queue<ll, vi, greater<ll>> pq;
public:
    Toposort(ll n) {
        MXN = n;
        tl.assign(MXN,0);
        AL.assign(n,{});
        vis.assign(n,0);
        deg.assign(n,0);
    }
    void addEdge(ll u, ll v) {AL[u].pb(v); deg[v]++;}
    void addEdgeTL(ll u, ll v) {AL[v].pb(u); deg[u]++;}
    
    void topo(ll u) {
        vis[u] = 1;
        for(auto &v : AL[u]) { if(!vis[v]) topo(v); }
        ts.pb(u);
    }
    vi toposort() {
        RFOR(i,0,MXN) {if(!vis[i]) topo(i);}
        //FOR(i,0,MXN) {if(!vis[i]) topo(i);}
        reverse(all(ts)); return ts;
    }
    
    vi khan() {
        FOR(u,0,MXN) {if(!deg[u]) pq.push(u);}
        while(!pq.empty()) {
            ll u = pq.top(); pq.pop(); ts.pb(u);
            for(auto &v : AL[u]) {
                --deg[v];
                if(!deg[v]) pq.push(v);
            }
        }   
        return ts;
    }
};
 
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, u, v; cin >> n >> m;
	Toposort tp(n); 
	
	FOR(_,0,m) {
		cin >> u >> v; --u, --v;
		tp.addEdge(u,v);
	}
 
	vi kh = tp.khan();
	if(kh.size() != n) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(auto u : kh) cout << u+1 << " "; cout << endl;
 
	return 0;
}