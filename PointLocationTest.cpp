#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

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

int location(pt a, pt b, pt p) {
    return sgn( (b.x-a.x)*(p.y-a.y) - (b.y-a.y)*(p.x-a.x) );
} // 1 LEFT, 0 TOUCH, -1 RIGHT


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ld t, x1, x2, x3, y1, y2, y3; cin >> t;
    FOR(_,0,t) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        pt a; a.x = x1, a.y = y1;
        pt b; b.x = x2, b.y = y2;
        pt p; p.x = x3, p.y = y3;
        int d = location(a,b,p);
        cout << (!d ? "TOUCH" : d==1 ? "LEFT" : "RIGHT") << endl;
    }
    return 0;
}