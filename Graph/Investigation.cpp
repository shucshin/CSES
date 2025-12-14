#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MOD = 1e9+7;
const ll INF = 1e18;
 
ll n, m;
vector<vector<pi>> AL;
vi dist, ways, minf, maxf;
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll u, v, w; cin >> n >> m;
	AL.assign(n+1,{});
	FOR(_,0,m) {
		cin >> u >> v >> w;
		AL[u].emplace_back(v, w);
	}
 
	dist.assign(n+1, INF);
	ways.assign(n+1, 0);
	minf.assign(n+1, INF);
	maxf.assign(n+1, 0);
 
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	dist[1] = 0; ways[1] = 1; minf[1] = 0; maxf[1] = 0;
	pq.emplace(0, 1);
	while(!pq.empty()) {
		auto [du, u] = pq.top(); pq.pop();
		if(du != dist[u]) continue;
		for(auto &[v, w] : AL[u]) {
			ll nd = du + w;
			if(nd < dist[v]) {
				dist[v] = nd;
				ways[v] = ways[u];
				minf[v] = minf[u] + 1;
				maxf[v] = maxf[u] + 1;
				pq.emplace(nd, v);
			} else if(nd == dist[v]) {
				ways[v] = (ways[v] + ways[u]) % MOD;
				minf[v] = min(minf[v], minf[u] + 1);
				maxf[v] = max(maxf[v], maxf[u] + 1);
			}
		}
	}
	
	cout << dist[n] << " " << ways[n] << " " << minf[n] << " " << maxf[n] << endl;
 
	return 0;
}