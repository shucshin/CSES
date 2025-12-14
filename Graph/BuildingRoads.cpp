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
 
    vi A;
    FOR(i,1,n+1) {
        if(!vis[i]) {
            A.pb(i);
            bfs(i);
        }
    }
 
    cout << A.size()-1 << endl;
    FOR(i,1,A.size()) {
        cout << A[i-1] << " " << A[i] << endl;
    }
 
    return 0;
}