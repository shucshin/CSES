#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int XMIN = 0;
const int XMAX = 100000; // inclusive domain for x
 
struct Line {
    ll m = 0, b = -(ll)4e18; // y = m*x + b ; default is -INF
    Line() {}
    Line(ll _m, ll _b) : m(_m), b(_b) {}
    inline ll eval(ll x) const { return m * x + b; }
};
 
struct Node {
    Line ln; bool has = false;
};
 
struct LiChao {
    vector<Node> st;
    LiChao() : st(4*(XMAX - XMIN + 5)) {}
 
    void addLineNode(ll p, ll L, ll R, Line nw) {
        if(!st[p].has) { st[p].ln = nw; st[p].has = true; return; }
        ll m = (L + R) >> 1;
        Line lo = st[p].ln, hi = nw;
        if(lo.eval(m) < hi.eval(m)) swap(lo, hi);
        st[p].ln = lo;
        if(L == R) return;
        if(lo.eval(L) < hi.eval(L)) addLineNode(p<<1, L, m, hi);
        else                        addLineNode(p<<1|1, m+1, R, hi);
    }
 
    void addRange(ll p, ll L, ll R, ll i, ll j, const Line &nw) {
        if(i > R || j < L) return;
        if(i <= L && R <= j) { addLineNode(p, L, R, nw); return; }
        ll m = (L + R) >> 1;
        addRange(p<<1,   L,   m, i, j, nw);
        addRange(p<<1|1, m+1, R, i, j, nw);
    }
 
    inline void add(ll l, ll r, ll m, ll b) {
        if(l > r) swap(l, r); // safety, though constraints guarantee l <= r
        addRange(1, XMIN, XMAX, l, r, Line(m, b));
    }
 
    ll queryPoint(ll p, ll L, ll R, ll x) const {
        ll ans = st[p].has ? st[p].ln.eval(x) : (-(ll)4e18);
        if(L == R) return ans;
        ll m = (L + R) >> 1;
        if(x <= m) return max(ans, queryPoint(p<<1, L, m, x));
        else       return max(ans, queryPoint(p<<1|1, m+1, R, x));
    }
 
    inline ll query(ll x) const { return queryPoint(1, XMIN, XMAX, x); }
};
 
void solve() {
    ll q; cin >> q;
    LiChao lichao;
    while(q--) {
        ll tp; cin >> tp;
        if(tp == 1) {
            ll a, b, l, r; cin >> a >> b >> l >> r;
            lichao.add(l, r, a, b);
        } else {
            ll x; cin >> x;
            ll res = lichao.query(x);
            if(res <= -(ll)3e18) cout << "NO" << endl;
            else cout << res << endl;
        }
    }
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
	return 0;
}