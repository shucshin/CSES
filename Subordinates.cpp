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

vector<vi> graph;
vi subtree;

void dfs(int s) {
    subtree[s] = 1;
    for(auto &v : graph[s]) {
        dfs(v);
        subtree[s] += subtree[v];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, v; cin >> n;
    graph.assign(n,{});
    subtree.assign(n,0); 
    FOR(u,1,n) {
        cin >> v; --v;
        graph[v].pb(u);
    }
    dfs(0);
    FOR(i,0,n) {
        cout << subtree[i]-1 << " ";
    } cout << endl;
    
    return 0;
}