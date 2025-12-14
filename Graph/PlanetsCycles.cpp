#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
 
class Toposort {
private:
    vector<vi> AL; ll MXN;
    vector<ll> ts, deg;
    priority_queue<ll, vi, greater<ll>> pq;
public:
    Toposort(ll n) {
        MXN = n;
        AL.assign(n,{});
        deg.assign(n,0);
    }
    void addEdge(ll u, ll v) {AL[u].pb(v); deg[v]++;}
    
    vi khan() {
        FOR(u,0,MXN) {if(!deg[u]) pq.push(u);}
        while(!pq.empty()) {
            ll u = pq.top(); pq.pop(); ts.pb(u);
            for(auto &v : AL[u]) {
                --deg[v];
                if(!deg[v]) pq.push(v);
            }
        }   
        return ts;
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi to(n, 0), ans(n, 0);
    FOR(i,0,n) { ll x; cin >> x; to[i] = x - 1; }
 
    Toposort tp(n);
    FOR(i,0,n) tp.addEdge(i, to[i]);
    vi order = tp.khan();
 
    vector<char> in_topo(n, 0);
    for(ll u : order) in_topo[u] = 1;
 
    FOR(i,0,n) {
        if(!in_topo[i] && ans[i] == 0) {
            ll u = i; vi cyc;
            do { cyc.pb(u); u = to[u]; } while(u != i);
            ll L = cyc.size();
            for(ll x : cyc) ans[x] = L;
        }
    }
 
    RFOR(idx,0,order.size()) {
        ll u = order[idx];
        ans[u] = ans[to[u]] + 1;
    }
 
    for(auto a : ans) cout << a << " "; cout << endl;
    return 0;
}