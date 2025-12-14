#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
 
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
};  pt operator*(ll a, pt b) {return b * a;}
 
ll areaPolygon(const vector<pt>& fig) {
    ll res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x-q.x) * (p.y+q.y);
    }
    return abs(res);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x, y; cin >> n;
    vector<pt> pts(n);
    FOR(i,0,n) {
        cin >> x >> y;
        pt p; p.x = x; p.y = y;
        pts[i] = p;
    }
    cout << areaPolygon(pts)<< endl;
    return 0;
}