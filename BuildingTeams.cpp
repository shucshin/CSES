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
vi color;
ll n;

pair<bool,vi> bipartite_check() {
    bool bipartite = 1; queue<ll> q;
    FOR(i,1,n+1) {
        if(color[i] != INF) continue;
        q.push(i); color[i] = 0;
        while(!q.empty()) {
            ll u = q.front(); q.pop();
            for(auto &v : AL[u]) {
                if(color[v] == INF) {color[v] = color[u]^1; q.push(v);} 
                else {bipartite &= color[u] != color[v];}
            }
        }
    }
    return {bipartite,color};
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll m, u, v; cin >> n >> m;
    AL.assign(n+1,{}); color.assign(n+1,INF);
    FOR(_,0,m) {
        cin >> u >> v;
        AL[u].pb(v); AL[v].pb(u);
    }

    pair<bool,vi> A = bipartite_check();
    if(A.fst == false) {
        cout << "IMPOSSIBLE\n";
    } else {
        FOR(i,1,n+1) cout << A.snd[i]+1 << " ";
        cout << endl;
    }

    return 0;
}