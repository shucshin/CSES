#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define endl '\n'
#define snd second
#define pb push_back
#define sq(a) (a) * (a)
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y): x(x), y(y) {}
    pt& operator+=(const pt &t) {x += t.x; y += t.y; return *this;}
    pt& operator-=(const pt &t) {x -= t.x; y -= t.y; return *this;}
    pt& operator*=(ll t) {x *= t; y *= t; return *this;}
    pt& operator/=(ll t) {x /= t; y /= t; return *this;}
    pt operator+(const pt &t) const {return pt(*this) += t;}
    pt operator-(const pt &t) const {return pt(*this) -= t;}
    pt operator*(ll t) const {return pt(*this) *= t;}
    pt operator/(ll t) const {return pt(*this) /= t;}
    ll cross(const pt& p) const {return x * p.y - y * p.x;}
    ll cross(const pt& a, const pt& b) const {return (a - *this).cross(b - *this);} 
};  pt operator*(ll a, pt b) {return b * a;}
int sgn(const ld &x) {return x >= 0 ? x ? 1 : 0 : -1;}
 
//==Distance from a to b squared==
ll dist_sq(pt a, pt b) {return sq(a.x - b.x) + sq(a.y - b.y);}
 
// Returns (py, best_d2) where py is points sorted by y, best_d2 is min squared dist
pair<vector<pt>, ll> min_euc_dst(vector<pt> &px) {
    int n = px.size();
    if(n <= 3){
        // brute‐force
        ll best = LLONG_MAX;
        FOR(i,0,n) FOR(j,i+1,n) best = min(best, dist_sq(px[i],px[j]));
        // sort by y
        auto py = px;
        sort(py.begin(), py.end(), [](auto &a, auto &b){
            return a.y < b.y;
        });
        return {py, best};
    }
    ll mid = n/2;
    ll midx = px[mid].x;
    // left / right halves by x
    vector<pt> Lx(px.begin(), px.begin()+mid),
               Rx(px.begin()+mid, px.end());
    auto lr = min_euc_dst(Lx);
    auto rr = min_euc_dst(Rx);
    ll d2 = min(lr.second, rr.second);
    // merge sorted‐by‐y lists
    vector<pt> py;
    py.reserve(n);
    auto &Ly = lr.first;
    auto &Ry = rr.first;
    int i = 0, j = 0;
    while(i < Ly.size() && j < Ry.size()){
        if(Ly[i].y < Ry[j].y) py.pb(Ly[i++]);
        else                  py.pb(Ry[j++]);
    }
    while(i < Ly.size()) py.pb(Ly[i++]);
    while(j < Ry.size()) py.pb(Ry[j++]);
 
    // build strip of points within |x-midx|^2 < d2
    vector<pt> strip;
    strip.reserve(n);
    for(auto &p: py){
        ll dx = p.x - midx;
        if(dx*dx < d2) strip.pb(p);
    }
    // scan strip: for each, compare next up to when dy^2 >= d2
    FOR(u,0,strip.size()) FOR(v,u+1,strip.size()) {
        ll dy = strip[v].y - strip[u].y;
        if(dy*dy >= d2) break;
        d2 = min(d2, dist_sq(strip[u], strip[v]));
    }
    return {py, d2};
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<pt> pts(n);
    FOR(i,0,n) cin >> pts[i].x >> pts[i].y;
 
    // sort by x, then by y
    sort(pts.begin(), pts.end(), [](auto &a, auto &b){
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
 
    auto res = min_euc_dst(pts);
    ll ans = res.snd;
    cout << ans << endl;
 
    return 0;
}