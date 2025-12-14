#include <bits/stdc++.h>
using namespace std;
using lli = __int128;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;
const ll INF = 1e9;

vector<vi> AL;
vi vis, color, par;
ll cycle_node = -1, cycle_ini, cycle_end;

// Finds the nearest cycle node from u (Undirected Graph)
bool cycleNode(int u, int p=-1) {
    vis[u] = 1;
    for(auto v : AL[u]) {
        if(v != p && vis[v]) {
            // already visited node that is not current node's parent
            cycle_node = v; return true;
        } else if(!vis[v]) {
            if(cycleNode(v,u)) return true;
        }
    } return false;
}

// dfs for Directed Graph
bool dfs_di(int u) {
    color[u] = 1;
    for(auto v : AL[u]) {
        if(color[v] == 0) {
            par[v] = u;
            if(dfs_di(v)) return true;
        } else if(color[v] == 1) {
            cycle_end = u;
            cycle_ini = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

// dfs for Undirected Graph
bool dfs_un(int u, int p=-1) {
    vis[u] = 1;
    for(auto v : AL[u]) {
        if(v==p) continue;
        if(vis[v]) {
            cycle_end = u;
            cycle_ini = v;
            return true;
        }
        par[v] = u;
        if(dfs_un(v,par[v])) return true;
    }
    return false;
}

vi find_cycle(ll n, bool directed=0) {
    FOR(u,1,n+1) { // 1-indexed
        if(directed) {if(color[u]==0 && dfs_di(u)) break;}
        else {if(!vis[u] && dfs_un(u,par[u])) break;}
    }
    if(cycle_ini == -1) return {};
    vi cycle; cycle.pb(cycle_ini);
    for(ll u = cycle_end; u != cycle_ini; u = par[u]) {
        cycle.pb(u);
    } cycle.pb(cycle_ini);
    if(directed) reverse(all(cycle));
    return cycle;
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v; cin >> n >> m;
    AL.assign(n+1,{}); vis.assign(n+1,0); color.assign(n+1,0); par.assign(n+1,-1); cycle_ini=-1;
    FOR(_,0,m) {
        cin >> u >> v;
        AL[u].pb(v);
    }
   
    vi A = find_cycle(n,1);
    if(A.empty()) cout << "IMPOSSIBLE\n";
    else {
        cout << A.size() << endl;
        for(auto a : A) cout << a << " ";
        cout << endl;
    }

    return 0;
}