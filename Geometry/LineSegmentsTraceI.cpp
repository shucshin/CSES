#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
// Li‐Chao tree for maximum of lines f(x)=k*x+b over x in [0..M]
struct LiChao {
    struct Line {
        ll k, b;
        Line(ll _k=0, ll _b=-INF): k(_k), b(_b) {}
        ll eval(ll x) const { return k*x + b; }
    };
    int M;
    vector<Line> st;
    LiChao(int _M): M(_M), st(4*_M+10, Line()) {}
 
    // Insert a new line into the tree
    void addLine(ll k, ll b) { addLine(1, 0, M, Line(k,b)); }
    void addLine(int p, int l, int r, Line nw) {
        int m = (l + r) >> 1;
        // At midpoint, keep the line that is better there
        if (nw.eval(m) > st[p].eval(m))
            swap(nw, st[p]);
        if (l == r) return;
        // Decide which side the losing line might beat the winner
        if (nw.eval(l) > st[p].eval(l))
            addLine(p<<1,   l,   m, nw);
        else if (nw.eval(r) > st[p].eval(r))
            addLine(p<<1|1, m+1, r, nw);
    }
 
    // Query maximum at x
    ll query(int x) const { return query(1,0,M,x); }
    ll query(int p, int l, int r, int x) const {
        ll res = st[p].eval(x);
        if (l == r) return res;
        int m = (l + r) >> 1;
        if (x <= m) return max(res, query(p<<1,   l,   m, x));
        else        return max(res, query(p<<1|1, m+1, r, x));
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    LiChao lc(m);
 
    FOR(i,0,n) {
        ll y1, y2; cin >> y1 >> y2;
        // slope k = (y2-y1)/m  (integer by problem statement)
        ll k = (y2 - y1) / m;
        ll b = y1;
        lc.addLine(k, b);
    }
    // Output max y for x = 0..m
    for(int x = 0; x <= m; x++){
        cout << lc.query(x) << " ";
    }   cout << endl;
    return 0;
}