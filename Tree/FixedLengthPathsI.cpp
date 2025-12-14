#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll n, k;
vector<vi> AL;
vi removed, sub, frq, touched;
ll ans = 0;
 
void get_size(ll u, ll p){
    sub[u] = 1;
    for(auto &v : AL[u]) if(v != p && !removed[v]){
        get_size(v, u);
        sub[u] += sub[v];
    }
}
 
ll get_centroid(ll u, ll p, ll tot){
    for(auto &v : AL[u]) if(v != p && !removed[v]){
        if(sub[v] > tot/2) return get_centroid(v, u, tot);
    }
    return u;
}
 
void collect(ll u, ll p, ll d, vi& dst){
    if(d > k) return;
    dst.pb(d);
    for(auto &v : AL[u]) if(v != p && !removed[v]) collect(v, u, d+1, dst);
}
 
void decompose(ll entry){
    get_size(entry, 0);
    ll c = get_centroid(entry, 0, sub[entry]);
    removed[c] = 1;
 
    touched.clear();
    if(frq.size() < k+1) frq.assign(k+1, 0);
    frq[0] = 1; touched.pb(0);
    for(auto &v : AL[c]) if(!removed[v]){
        vi dst; dst.reserve(sub[v]);
        collect(v, c, 1, dst);
        for(auto &d : dst) if(d <= k) {
            ll need = k - d;
            if(need >= 0) ans += frq[need];
        }
        for(auto &d : dst) if(d <= k) {
            if(frq[d] == 0) touched.pb(d);
            frq[d]++;
        }
    }
    for(auto &x : touched) frq[x] = 0;
 
    for(auto &v : AL[c]) if(!removed[v]) decompose(v);
}
 
void solve(){
    cin >> n >> k;
    AL.assign(n+1, {});
    FOR(_,0,n-1){ ll a,b; cin >> a >> b; AL[a].pb(b); AL[b].pb(a); }
    removed.assign(n+1, 0); sub.assign(n+1, 0);
    frq.assign(k+1, 0); touched.clear(); ans = 0;
    decompose(1);
    cout << ans << endl;
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}