#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
ll n, m;
 
vi dijkstra(vector<vector<pi>> &AL, ll s) {
    vi dst(n+1, INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(0,s); dst[s] = 0;
    while(!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if(du != dst[u]) continue;
        for(auto &[v,w] : AL[u]) {
            ll nd = du + w;
            if(nd >= dst[v]) continue;
            dst[v] = nd;
            pq.emplace(nd, v);
        }
    }
	return dst;
}
 
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll u, v, w; cin >> n >> m;
	vector<vector<pi>> AL(n+1), rAL(n+1);
	FOR(_,0,m) {
		cin >> u >> v >> w;
		AL[u].emplace_back(v, w);
		rAL[v].emplace_back(u, w);
	}
 
	vi d1 = dijkstra(AL, 1);
	vi dn = dijkstra(rAL, n);
 
	ll ans = INF;
	FOR(u,1,n+1) {
		for(auto &[v,w] : AL[u]) {
			if(d1[u] == INF || dn[v] == INF) continue;
			ans = min(ans, d1[u] + (w / 2) + dn[v]);
		}
	}
	cout << ans << endl;
 
	return 0;
}