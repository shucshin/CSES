// Lowest Common Ancestor (Binary Lifting)
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)

class LCA {
private:
    vector<vi> graph, up;
    vi depth; ll l, MAXN;
public:
    LCA(ll n) {
        graph.assign(n,{}); up.assign(n,vi(20));
        depth.assign(n,0);
        FOR(i,0,n) {up[i][0] = i;}
        l = ceil(log2(n)); MAXN = n;
    }
    void addEdge(ll u, ll v) {graph[u].pb(v); graph[v].pb(u);}
    void init() {
        dfs(0);
        FOR(i,1,l) {FOR(j,0,MAXN) up[j][i] = up[up[j][i-1]][i-1];}
    }

    void dfs(ll u) {
        for(auto &v : graph[u]) {
            if(v != up[u][0]) {
                depth[v] = depth[up[v][0]=u]+1;
                dfs(v);
            }
        }
    }

    ll jump(ll x, ll d) {
        FOR(i,0,l) {if((d>>i)&1) x = up[x][i];} 
        return x;
    }

    ll lca(ll u, ll v) {
        if(depth[u] < depth[v]) swap(u,v);
        u = jump(u, depth[u]-depth[v]);
        if(u==v) return u;
        RFOR(i,0,l) {
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        }
        return up[u][0];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, q, u, v; cin >> n >> q;
    LCA anc(n); 
    FOR(u,1,n) {
        cin >> v; --v;
        anc.addEdge(u,v);
    }
    anc.init();
    FOR(i,0,q) {
        cin >> u >> v; --u; --v;
        cout << anc.lca(u,v)+1 << endl;
    }
    return 0;
}