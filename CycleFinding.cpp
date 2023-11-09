// Bellman-Ford Algorithm
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

struct Edge {ll u, v, w;};
vector<Edge> edges;
vi d, p; // d = distance, p = parent

// Finding Negative Cycle with Bellman-Ford
vi bellmanFordNC(ll s, ll n) {
    ll x; d[s] = 0;
    FOR(_,0,n) {
        x = -1;
        for(Edge e : edges)
            if(d[e.u] < INF)
                if(d[e.v] > d[e.u]+e.w) {
                    d[e.v] = max(-INF,d[e.u]+e.w);
                    p[e.v] = e.u;
                    x = e.v;
                }
    }
    if(x==-1) {return {};} // no Neg Cycle
    FOR(_,0,n) x = p[x];
    vi cycle;
    for(ll u=x;;u=p[u]) {
        cycle.pb(u);
        if(u==x && cycle.size()>1) break;
    } reverse(all(cycle));
    return cycle;
}


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v, w; cin >> n >> m;
    d.assign(n+1,0); p.assign(n+1,-1);
    FOR(_,0,m) {
        cin >> u >> v >> w;
        edges.pb({u,v,w}); 
    }
    vi A = bellmanFordNC(1,n+1);
    if(!A.size()) cout << "NO\n";
    else {
        cout << "YES\n";
        for(auto a : A) cout << a << " ";
    } cout << endl;

    return 0;
}
