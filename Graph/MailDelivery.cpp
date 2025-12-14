#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
class EulerianUndirected {
private:
    ll n, m;
    vector<vector<pi>> AL;     // (neighbor, edge_id)
    vi degree;                 // degrees per vertex
    vector<char> edgeUsed;     // used[edge_id]
 
    bool isConnectedFromOne() {
        if (m == 0) return true; // no edges at all
        if (degree[1] == 0) return false; // edges exist but not attached to 1
        vi vis(n+1, 0);
        queue<ll> q; q.push(1); vis[1] = 1;
        while(!q.empty()) {
            ll u = q.front(); q.pop();
            for(auto &[v, id] : AL[u]) {
                if(!vis[v]) { vis[v] = 1; q.push(v); }
            }
        }
        FOR(i,1,n+1) if (degree[i] > 0 && !vis[i]) return false;
        return true;
    }
 
public:
    EulerianUndirected(ll n_) {
        n = n_; m = 0;
        AL.assign(n+1, {});
        degree.assign(n+1, 0);
    }
 
    void addEdge(ll u, ll v) {
        AL[u].pb({v, m});
        AL[v].pb({u, m});
        degree[u]++; degree[v]++; m++;
    }
 
    bool hasEulerianCycleFromOne() {
        if(!isConnectedFromOne()) return false;
        FOR(i,1,n+1) if (degree[i] & 1) return false;
        return true;
    }
 
    // If exists, returns vertex-sequence of length m+1 starting at 1. Else empty
    vi getPath() {
        if (m == 0) return {1};
        if(!hasEulerianCycleFromOne()) return {};
        ll start = 1;
 
        edgeUsed.assign(m, 0);
        vi idx(n+1, 0), path, stk;
        ll u = start;
        while(true) {
            while(idx[u] < (ll)AL[u].size()) {
                auto [v, id] = AL[u][idx[u]++];
                if(edgeUsed[id]) continue;
                edgeUsed[id] = 1;
                stk.pb(u);
                u = v;
            }
            path.pb(u);
            if(stk.empty()) break;
            u = stk.back(); stk.pop_back();
        }
        if((ll)path.size() != m + 1) return {};
        reverse(all(path));
        return path;
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    EulerianUndirected EU(n);
    FOR(i,0,m) { ll u, v; cin >> u >> v; EU.addEdge(u, v); }
    vi path = EU.getPath();
    if(path.empty()) cout << "IMPOSSIBLE\n";
    else {
        for(auto p : path) cout << p << " "; cout << endl;
    }
    return 0;
}