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
    ll l, n;
public:
    LCA(ll n) {
        this->n = n;
        graph.assign(n+1,{}); up.assign(n+1,vi(20));
        l = ceil(log2(n))+1;
    }
    void addEdge(ll u, ll v) {graph[v].pb(u);}
    void init() {
        dfs(1); 
        FOR(i,1,l) {
            FOR(j,1,n+1) {
                up[j][i] = up[up[j][i-1]][i-1];
                
            }
        }
    }

    void dfs(ll u) {
        for(auto &v : graph[u]) {
            if(v != up[u][0]) {
                up[v][0]=u;
                dfs(v);
            }
        }
    }

    ll jump(ll x, ll d) {
        FOR(i,0,l) {
            if((d>>i)&1) x = up[x][i]; 
        } return x ?: -1;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, q, u, v; cin >> n >> q;
    LCA anc(n); 
    FOR(u,2,n+1) {
        cin >> v;
        anc.addEdge(u,v);
    }
    anc.init();
    FOR(i,0,q) {
        cin >> u >> v;
        cout << anc.jump(u,v) << endl;
    }
    return 0;
}