#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
ll n, m, k;
vector<vector<pi>> AL;
vector<vi> dst;
 
void dijkstra(ll s) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(0,s);
    while(!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if(dst[u].size() >= k) continue;
        dst[u].pb(du);
        for(auto &[v,w] : AL[u]) {
            ll nd = du + w;
            if(dst[v].size() < k) pq.emplace(nd, v);
        }
    }
}
 
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll u, v, w; cin >> n >> m >> k;
	AL.assign(n+1,{});
	dst.assign(n+1,{});
	FOR(_,0,m) {
		cin >> u >> v >> w;
		AL[u].emplace_back(v, w);
	}
 
	dijkstra(1);
 
	FOR(i,0,k) {
		cout << dst[n][i] << " ";
	}	cout << endl;
 
	return 0;
}