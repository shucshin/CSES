#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ld>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ald(a) (a).begin(), (a).end()

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
    ld cross(const pt& p) const {return x*p.y - y*p.x;}
    ld cross(const pt& a, const pt& b) const {return (a-*this).cross(b-*this);} 
};  pt operator*(ld a, pt b) {return b * a;}

int sgn(const ld &x) {return x >= 0 ? x ? 1 : 0 : -1;}
bool inter(ld a, ld b, ld c, ld d) {
    if(a > b) swap(a,b);
    if(c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}

bool intersect(pt a, pt b, pt c, pt d) {
    if(c.cross(a,d) == 0 && c.cross(b,d) == 0) {
        return inter(a.x, b.x, c.x, d.x) 
            && inter(a.y, b.y, c.y, d.y);
    }
    return sgn(a.cross(b,c)) != sgn(a.cross(b,d)) 
        && sgn(c.cross(d,a)) != sgn(c.cross(d,b));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ld t, x1, x2, x3, x4, y1, y2, y3, y4; cin >> t;
    FOR(_,0,t) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pt a; a.x = x1, a.y = y1;
        pt b; b.x = x2, b.y = y2;
        pt c; c.x = x3, c.y = y3;
        pt d; d.x = x4, d.y = y4;
        cout << (intersect(a,b,c,d) ? "YES" : "NO") << endl;
    }
    return 0;
}