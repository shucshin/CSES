// Dijkstra Algorithm
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

vector<vector<pi>> AL;
vi d, p; // d = distance, p = parent

// Dijkstra with Set (Red-Black Trees), supports removing elems
void dijkstraSet(ll s, ll x=-1) { // Exclude node x
    set<pi> q;
    q.insert({0,s}); d[s] = 0;
    while(!q.empty()) {
        ll u = q.begin()->snd; q.erase(q.begin());
        if(u == x) continue;
        for(auto a : AL[u]) {
            ll v = a.fst, w = a.snd;
            if(d[u] + w < d[v]) {
                q.erase({d[v],v});
                d[v] = d[u]+w;
                p[v] = u;
                q.insert({d[v],v});
            }
        }
    }
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v, w; cin >> n >> m;
    AL.assign(n+1,{}); d.assign(n+1,INF); p.assign(n+1,-1);
    FOR(_,0,m) {
        cin >> u >> v >> w;
        AL[u].pb({v,w});
    }
    dijkstraSet(1);
    FOR(i,1,n+1) cout << d[i] << " "; cout << endl;
    return 0;
}
