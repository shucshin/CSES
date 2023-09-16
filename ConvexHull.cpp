#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)

struct pt{ll id; ld x, y;}; 
// This is necessary to be able to use set<pt>
bool operator<(const pt &p, const pt &q) {
    return mp(p.y, p.x) < mp(q.y, q.x);
}

// Direction :: collinear 0, clockwise -1, counterclockwise 1;
int orientation(pt p, pt q, pt r) {
    ld v = (r.y-p.y)*(q.x-p.x)-(q.y-p.y)*(r.x-p.x);
    return !v ? 0 : (v < 0 ? -1 : 1);
}

bool cw(pt p, pt q, pt r, bool collinear) {
    int o = orientation(p,q,r);
    return o < 0 || (collinear && o == 0);
}

bool ccw(pt p, pt q, pt r, bool collinear) {
    int o = orientation(p, q, r);
    return o > 0 || (collinear && o == 0);
}

vector<pt> monotoneChain(vector<pt> &A, bool collinear = 0) {
    if(A.size() == 1) return A;
    sort(all(A), [](pt p, pt q){return mp(p.x, p.y) < mp(q.x, q.y);}); 
    pt p1 = A[0], p2 = A.back();
    vector<pt> up, down; up.pb(p1); down.pb(p1);
    FOR(i,1,A.size()) {
        if(i == A.size()-1 || cw(p1, A[i], p2, collinear)) {
            while(up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], A[i], collinear)) up.pop_back();
            up.pb(A[i]);
        }
        if(i == A.size()-1 || ccw(p1, A[i], p2, collinear)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], A[i], collinear)) down.pop_back();
            down.pb(A[i]);
        }
    }
    if(collinear && up.size() == A.size()) {reverse(all(A)); return A;}
    A.clear();
    FOR(i,0,up.size()) A.pb(up[i]);
    RFOR(i,1,down.size()-1) A.pb(down[i]);
    return A;
}

int main() {
    ios::sync_with_stdio(1); cin.tie(0);
    int n, x, y; cin >> n;
    vector<pt> pts;
    FOR(i,0,n) {
        cin >> x >> y;
        pt p; p.x = x; p.y = y;
        pts.pb(p);
    }
    vector<pt> mc = monotoneChain(pts, 1);
    cout << mc.size() << endl;
    for(auto p : mc) {
        printf("%lld %lld\n", (ll)p.x, (ll)p.y);
    }
    return 0;
}