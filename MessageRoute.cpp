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
vi vis, d, p; // d = distance, p = parent
 
// Breath First Search
void bfs(ll s) {
    vis[s] = 1;
    queue<ll> q; q.push(s);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : AL[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                d[v] = d[u]+1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}
 
// Gets path from initial node to node u
vi getPath(ll u) {
    vi A = {u};
    while(p[u] != -1) {
        A.pb(p[u]);
        u = p[u];
    } reverse(all(A));
    return A;
}
 
// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v; cin >> n >> m;
    AL.assign(n+1,{}); d.assign(n+1,0); p.assign(n+1,-1), vis.assign(n+1,0);
    FOR(_,0,m) {
        cin >> u >> v;
        AL[u].pb(v); AL[v].pb(u); 
    }
 
    bfs(1);
    vi A = getPath(n);
    if(A[0] != 1) cout << "IMPOSSIBLE\n";
    else {
        cout << A.size() << endl;
        for(auto a : A) cout << a << " "; cout << endl;
    }
 
    return 0;
}