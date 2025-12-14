#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e18;
 
struct Edge {ll u, v, w;};
 
vector<vector<pi>> AL;
vector<Edge> edges;
vi dst, p; // dst = distance, p = parent
ll n, m;
 
// Finding Negative Cycle with Bellman-Ford
vi find_negative_cycle(ll s) { // dst.assign(n+1,0); for Cycle Finding
    ll x; dst[s] = 0;
    FOR(_,0,n) {
        x = -1;
        for(auto &[u,v,w] : edges) {
            if(dst[u] == INF || dst[v] <= dst[u] + w) continue;
            dst[v] = max(dst[u] + w, -INF);
            p[v]   = u;
            x      = v;
        }
    }
    if(x == -1) return {}; // no Neg Cycle
 
    FOR(_,0,n) x = p[x];
    vi cycle;
    for(ll u = x;; u = p[u]) {
        cycle.pb(u);
        if(u == x && cycle.size() > 1) break;
    }   reverse(all(cycle));
    return cycle;
}
 
// Mark nodes that belong in a Neg Cycle w/ -INF
void negative_infinity() { // use find_negative_cycle() before
    queue<ll> q;
    vi inq(n+1, 0);
    FOR(u,1,n+1) { // u,1,n+1 for 1-indexed
        if(dst[u] == INF) continue;
        for(auto &[v,w] : AL[u]) {
            if(dst[v] > dst[u] + w && !inq[v]) {
                q.push(v);
                inq[v] = 1;
            }
        }
    }
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        dst[u] = -INF;
        for(auto &[v,w] : AL[u]) {
            if(!inq[v]) {
                inq[v] = 1;
                q.push(v);
            }
        }
    }
}
 
vi getPath(ll t) {
    vi path;
    if(dst[t] == INF) return path;
    for(ll u = t; u != -1; u = p[u]) path.pb(u);
    reverse(all(path));
    return path;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll u, v, w; cin >> n >> m;
	AL.assign(n+1,{});
	dst.assign(n+1,INF), p.assign(n+1,-1);
 
	FOR(_,0,m) {
		cin >> u >> v >> w;
		AL[u].emplace_back(v,-w);
		edges.pb({u,v,-w});
	}
 
	find_negative_cycle(1);
	negative_infinity();
 
	if(dst[n] == -INF || dst[n] == INF) {
		cout << -1 << endl;
	} else {
		cout << -dst[n] << endl;
	}
 
	return 0;
}