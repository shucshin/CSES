#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
// Fenwick tree for point updates and prefix sums
struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    // add v at index i (1-based)
    void update(int i, ll v){
        for(; i <= n; i += i & -i) f[i] += v;
    }
    // sum of [1..i]
    ll query(int i) const {
        ll s = 0;
        for(; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    // sum of [l..r]
    ll query(int l, int r) const {
        if(l > r) return 0;
        return query(r) - query(l-1);
    }
};
 
struct Event {
    ll x;
    ll type; // 0 = add horizontal, 1 = remove horizontal, 2 = query vertical
    ll y1, y2; // for add/remove: y1 = y, y2 unused; for query: y1..y2 range
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    
    vector<tuple<ll,ll,ll,ll>> segs(n);
    FOR(i,0,n) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        segs[i] = make_tuple(x1,y1,x2,y2);
    }
 
    // collect all y coordinates for compression
    vector<ll> ys; ys.reserve(2*n);
    for(auto &t: segs) {
        ll x1, y1, x2, y2; tie(x1, y1, x2, y2) = t;
                     ys.pb(y1);
        if(y1 != y2) ys.pb(y2);
    }   sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
 
    auto getY = [&](int y){
        return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
    };
 
    // build events
    vector<Event> ev; ev.reserve(2*n);
    for(auto &t: segs){
        ll x1, y1, x2, y2; tie(x1, y1, x2, y2) = t;
        if(y1 == y2){
            // horizontal segment at y=y1, from x1..x2
            ll cy = getY(y1);
            ev.pb({x1, 0, cy, 0});        // add at x1
            ev.pb({x2+1, 1, cy, 0});      // remove at x2+1
        } else {
            // vertical segment at x=x1==x2, from y1..y2
            ll cy1 = getY(y1);
            ll cy2 = getY(y2);
            if(cy1 > cy2) swap(cy1, cy2);
            ev.pb({x1, 2, cy1, cy2});
        }
    }
 
    // sort events by x, then type (0,1,2)
    sort(ev.begin(), ev.end(), [](auto &a, auto &b){
        if(a.x != b.x) return a.x < b.x;
        return a.type < b.type;
    });
 
    Fenwick fw((int)ys.size());
    ll ans = 0;
    for(auto &e: ev){
        if(e.type == 0){
            // add horizontal
            fw.update(e.y1, +1);
        } else if(e.type == 1){
            // remove horizontal
            fw.update(e.y1, -1);
        } else {
            // query vertical: count horizontals covering this x whose y in [y1..y2]
            ans += fw.query(e.y1, e.y2);
        }
    }
    cout << ans << endl;
 
    return 0;
}