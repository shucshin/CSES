#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
 
class Toposort {
private:
    vector<vi> AL; ll MXN;
    vector<ll> ts, deg;
    priority_queue<ll, vi, greater<ll>> pq;
public:
    Toposort(ll n) {
        MXN = n;
        AL.assign(n,{});
        deg.assign(n,0);
    }
    void addEdge(ll u, ll v) {AL[u].pb(v); deg[v]++;}
    
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
    ll n, q; cin >> n >> q;
    vi to(n, 0);
    FOR(i,0,n) { ll x; cin >> x; to[i] = x - 1; }
 
    // Kahn to prune trees and get order of non-cycle nodes
    Toposort tp(n);
    FOR(i,0,n) tp.addEdge(i, to[i]);
    vi order = tp.khan();
    vector<char> in_topo(n, 0);
    for(ll u : order) in_topo[u] = 1;
 
    // Identify cycles and assign cycle ids and positions
    vi cycleId(n, -1), pos(n, -1), entry(n, -1), depth(n, 0);
    vi cycleLen; cycleLen.reserve(n);
    ll cid = 0;
    FOR(i,0,n) if(!in_topo[i] && cycleId[i] == -1) {
        ll u = i; ll k = 0;
        do {
            cycleId[u] = cid;
            pos[u] = k++;
            entry[u] = u;
            depth[u] = 0;
            u = to[u];
        } while(u != i);
        cycleLen.pb(k);
        cid++;
    }
 
    // Compute depth (distance to cycle), entry (first cycle node), and cycleId for tree nodes in reverse order
    RFOR(idx,0,order.size()) {
        ll u = order[idx];
        ll v = to[u];
        if(pos[v] != -1) { // v is on cycle
            entry[u] = v;
            depth[u] = 1;
            cycleId[u] = cycleId[v];
        } else { // v is a tree node leading to a cycle
            entry[u] = entry[v];
            depth[u] = depth[v] + 1;
            cycleId[u] = cycleId[v];
        }
    }
 
    // Binary lifting for jumps
    const ll LOG = 20;
    vector<vi> up(LOG, vi(n, 0));
    FOR(i,0,n) up[0][i] = to[i];
    FOR(k,1,LOG) FOR(i,0,n) up[k][i] = up[k-1][ up[k-1][i] ];
    auto jump = [&](ll u, ll k) {
        FOR(b,0,LOG) if((k >> b) & 1LL) u = up[b][u];
        return u;
    };
 
    while(q--) {
        ll a, b; cin >> a >> b; a--, b--;
        if(cycleId[a] != cycleId[b]) { cout << -1 << endl; continue; }
        if(pos[b] == -1) {
            if(depth[a] < depth[b]) { cout << -1 << endl; continue; }
            ll d = depth[a] - depth[b];
            ll c = jump(a, d);
            cout << (c == b ? d : -1) << endl;
        } else {
            ll e = (pos[a] != -1 ? a : entry[a]); // cycle node reached from a
            ll L = cycleLen[ cycleId[b] ];
            ll cycDist = (pos[b] - pos[e] + L) % L;
            cout << (depth[a] + cycDist) << endl;
        }
    }
    return 0;
}