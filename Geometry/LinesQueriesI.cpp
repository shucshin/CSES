#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MXN = 2e5+5;
const ll INF = 1e18;
 
// A line y = a*x + b
struct Line {
    ll a, b;
    Line(ll _a=0, ll _b=-INF): a(_a), b(_b) {}
    ll eval(int x) const { return a*(ll)x + b; }
};
 
// Li‐Chao tree for maximum queries on x in [0..XMAX]
struct LiChao {
    int XMAX;
    vector<Line> st;
    LiChao(int _XMAX): XMAX(_XMAX) {
        st.assign(4*(XMAX+1), Line());
    }
    // insert line into the tree
    void addLine(const Line &nw) { addLine(1, 0, XMAX, nw); }
    void addLine(int p, int l, int r, Line nw) {
        int m = (l + r) >> 1;
        // at midpoint, keep the better line
        if (nw.eval(m) > st[p].eval(m))
            swap(nw, st[p]);
        if (l == r) return;
        // on left interval?
        if (nw.eval(l) > st[p].eval(l))
            addLine(p<<1,   l,    m, nw);
        else
            addLine(p<<1|1, m+1,  r, nw);
    }
    // query max at x
    ll query(int x) const { return query(1, 0, XMAX, x); }
    ll query(int p, int l, int r, int x) const {
        ll res = st[p].eval(x);
        if (l == r) return res;
        int m = (l + r) >> 1;
        if (x <= m) return max(res, query(p<<1,   l,    m, x));
        else        return max(res, query(p<<1|1, m+1,  r, x));
    }
};
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    LiChao lc(MXN);
 
    FOR(i,0,n) {
        ll t; cin >> t;
 
        if(t == 1){
            ll a, b; cin >> a >> b;
            lc.addLine(Line(a, b));
        } else {
            ll x; cin >> x;
            ll ans = lc.query(x);
            // if no line was added before, ans might be -INF,
            // but problem guarantees first query is type 1.
            cout << ans << endl;
        }
    }
    return 0;
}