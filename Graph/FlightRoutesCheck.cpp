#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
#define pb push_back
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()

const int MAXN = 1e5+1;
vi graph[MAXN];
vi graphR[MAXN];
vi visited(MAXN,0);
vi topological;

void dfs(int s) {
    visited[s] = 1;
    for(int u : graph[s]) {
        if(!visited[u]) dfs(u);
    }
}

void dfsR(int s) {
    visited[s] = 1;
    for(int u : graphR[s]) {
        if(!visited[u]) dfsR(u);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, m, u, v; cin >> n >> m;
    rep(i,0,m) {
        cin >> u >> v;
        graph[u].pb(v);
        graphR[v].pb(u);
    }
    dfs(1);
    rep(i,1,n+1) {
        if(!visited[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << endl;
            return 0;
        }
    }
    rep(i,0,n+1) visited[i] = 0;
    dfsR(1);
    int c = 0; bool swt = false;
    rep(i,1,n+1) {
        if(!visited[i]) {
            if(!c) cout << "NO\n";
            cout << i << " " << 1 << endl; 
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}