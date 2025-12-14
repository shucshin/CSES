#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
using ti = tuple<ll,ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
struct edge {ll u, v, w;};
// < Minimum Spanning Tree, > Maximum Spanning Tree
bool cmp(edge a, edge b) {return a.w < b.w;}
 
class MST {
private:
    vector<edge> EL, mst;
    ll MXN, sz = 0, cost = 0;
    vector<vector<pi>> AL;
    vi vis, used;
    priority_queue<ti> pq;
public:
    MST(ll n) {
        MXN = n;
        AL.assign(n, {});
        vis.assign(n, 0);
    }
    void addEdge(ll u, ll v, ll w) {
        EL.pb({u, v, w});
        AL[u].pb({v, w});
        AL[v].pb({u, w});
    }
 
    ll total_cost() { return cost; }
    vector<edge>& get_mst() { return mst; }
 
    void process(ll u) { // for Prim
        vis[u] = 1;
        for(auto &[v, w] : AL[u]) {
            if(!vis[v]) pq.emplace(-w, u, v);
        }
    }
 
    void Prim() {
        process(0);
        while(!pq.empty()) {
            auto [w, u, v] = pq.top(); pq.pop();
            w = -w;
            if(vis[v]) continue;
            cost += w;
            mst.pb({u,v,w});
            process(v);
            if(++sz == MXN-1) break;
        }
    }
};
 
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, u, v, w; cin >> n >> m;
	MST st(n);
	FOR(_,0,m) {
		cin >> u >> v >> w; --u, --v;
		st.addEdge(u, v, w);
	}
	st.Prim();
	if(st.get_mst().size() != n-1) cout << "IMPOSSIBLE" << endl;
	else cout << st.total_cost() << endl;
 
	return 0;
}