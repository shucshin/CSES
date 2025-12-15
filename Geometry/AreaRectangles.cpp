#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
struct Event {
    ll x;
    ll y1, y2;
    ll delta; // +1 for rectangle start, -1 for end
};
 
ll N;
vector<ll> ys;
vector<Event> events;
vector<ll> cnt, seglen;
 
// Build segment tree arrays of size 4*(M)
void init_tree(ll M) {
    cnt.assign(4*M, 0);
    seglen.assign(4*M, 0);
}
 
// Update cover count on interval [ql..qr] in tree node p covering [l..r]
void update(ll p, ll l, ll r, ll ql, ll qr, ll delta) {
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        cnt[p] += delta;
    } else {
        ll m = (l + r) >> 1;
        update(p<<1,   l,   m, ql, qr, delta);
        update(p<<1|1, m+1, r, ql, qr, delta);
    }
    if(cnt[p] > 0) {
        // fully covered
        seglen[p] = ys[r+1] - ys[l];
    } else if(l == r) {
        seglen[p] = 0;
    } else {
        seglen[p] = seglen[p<<1] + seglen[p<<1|1];
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n; cin >> n;
    events.reserve(2*n);
    ys.reserve(2*n);
 
    FOR(i,0,n) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // record y-coords for compression
        ys.pb(y1);
        ys.pb(y2);
        // event at x1: add coverage [y1,y2)
        // event at x2: remove coverage
        events.pb({x1, y1, y2, +1});
        events.pb({x2, y1, y2, -1});
    }
 
    // compress y
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    ll M = ys.size();
    // we will build tree over intervals [0..M-2], each representing [ys[i],ys[i+1])
    init_tree(M);
 
    // remap event y to indices
    for(auto &e: events){
        e.y1 = int(lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin());
        e.y2 = int(lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin());
        // we want to cover [y1..y2-1] in terms of segments
        e.y2--;
    }
 
    // sort events by x
    sort(events.begin(), events.end(), [](auto &a, auto &b){
        return a.x < b.x;
    });
 
    ll area = 0, idx = 0;
    ll prev_x = events[0].x;
    ll E = events.size();
    while(idx < E){
        ll x = events[idx].x;
        ll dx = ll(x - prev_x);
        if(dx > 0){
            // add area = covered_y_length * dx
            area += seglen[1] * dx;
            prev_x = x;
        }
        // process all events at this x
        while(idx < E && events[idx].x == x){
            auto &e = events[idx++];
            if(e.y1 <= e.y2)
                update(1, 0, M-2, e.y1, e.y2, e.delta);
        }
    }
    cout << area << endl;
 
    return 0;
}