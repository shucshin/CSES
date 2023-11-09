// Floyd Warshall
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
const ll INF = 1e18;
const ll MXN = 5e2+5;
 
vector<vi> fw(MXN,vi(MXN,INF)); // for Floyd-Warshall
 
void floydWarshall(ll n) {
    FOR(i,0,n) fw[i][i] = 0;
    FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) {
        if(fw[i][k] < INF && fw[k][j] < INF) 
            fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
    }
    FOR(i,0,n) FOR(j,0,n) FOR(k,0,n) { // Negative Cycles
        if(fw[k][k] < 0 && fw[i][k] < INF && fw[k][j] < INF) fw[i][j] = -INF;
    }
}
 
 
// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, q, u, v, w; cin >> n >> m >> q;
    // Edges
    FOR(_,0,m) {
        cin >> u >> v >> w;
        fw[u][v] = min(fw[u][v],w); fw[v][u] = min(fw[v][u],w);
        // if(w < fw[u][v]) {fw[u][v] = fw[v][u] = w;} 
    }
    floydWarshall(n+1);
    // Queries
    FOR(_,0,q) {
        cin >> u >> v;
        if(fw[u][v]==INF) cout << "-1\n"; // No Route
        else if(fw[u][v]==-INF) cout << "-Infinity\n"; // Neg Cycle
        else cout << fw[u][v] << endl;
    }
 
    // Reset
    // FOR(i,0,n) FOR(j,0,n) fw[i][j] = INF;
 
    return 0;
}