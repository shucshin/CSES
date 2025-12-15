#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

static const ld EPS = 1e-12L;
 
struct pt {
    ld x, y;
    pt() {}
    pt(ld x, ld y): x(x), y(y) {}
    pt& operator+=(const pt &t) {x += t.x; y += t.y; return *this;}
    pt& operator-=(const pt &t) {x -= t.x; y -= t.y; return *this;}
    pt& operator*=(ld t) {x *= t; y *= t; return *this;}
    pt& operator/=(ld t) {x /= t; y /= t; return *this;}
    pt operator+(const pt &t) const {return pt(*this) += t;}
    pt operator-(const pt &t) const {return pt(*this) -= t;}
    pt operator*(ld t) const {return pt(*this) *= t;}
    pt operator/(ld t) const {return pt(*this) /= t;}
    ld cross(const pt& p) const {return x * p.y - y * p.x;}
    ld cross(const pt& a, const pt& b) const {return (a - *this).cross(b - *this);} 
};  pt operator*(ld a, pt b) {return b * a;}
int sgn(const ld &x) {return x >= 0 ? x ? 1 : 0 : -1;}
 
// Direction :: collinear 0, clockwise -1, counterclockwise 1;
int orientation(pt p, pt q, pt r) {
    ld v = (r.y - p.y) * (q.x - p.x) - (q.y - p.y) * (r.x - p.x);
    return !v ? 0 : (v < 0 ? -1 : 1);
}
 
// check if p lies on segment [a,b]
bool onSegment(const pt &a, const pt &b, const pt &p){
    if(orientation(a,b,p)!=0) return false;
    // check bounding box
    ld minx = min(a.x,b.x), maxx = max(a.x,b.x);
    ld miny = min(a.y,b.y), maxy = max(a.y,b.y);
    return p.x + EPS >= minx && p.x <= maxx + EPS
        && p.y + EPS >= miny && p.y <= maxy + EPS;
}
 
// returns true if ray to +x from p crosses segment [a,b]
bool rayIntersects(const pt &p, const pt &a, const pt &b){
    // one endpoint above, one below (half-open)
    if( (a.y > p.y) == (b.y > p.y) ) return false;
    // compute x coordinate of intersection of line ab with horizontal y=p.y
    ld xint = a.x + (p.y - a.y)*(b.x - a.x)/(b.y - a.y);
    return xint > p.x;
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll n, m; cin >> n >> m;
    vector<pt> poly(n);
    FOR(i,0,n) {
        ll xi, yi; cin >> xi >> yi;
        poly[i] = pt((ld)xi, (ld)yi);
    }
 
    // process queries
    FOR(_,0,m) {
        ll xi, yi; cin >> xi >> yi;
        pt p((ld)xi, (ld)yi);
 
        // 1) boundary check
        bool in = false;
        FOR(i,0,n) {
            ll j = (i+1) % n;
            if(onSegment(poly[i], poly[j], p)){
                in = true;
                break;
            }
        }   if(in) { cout << "BOUNDARY" << endl; continue; }
 
        // 2) ray-casting parity
        ll cnt = 0;
        FOR(i,0,n) {
            ll j = (i+1) % n;
            if(rayIntersects(p, poly[i], poly[j])) cnt++;
        }
 
        cout << ((cnt & 1) ? "INSIDE" : "OUTSIDE") << endl;
 
    }
    return 0;
}