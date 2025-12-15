#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
// A line f(x)=k*x+b
struct Line {
    ll k, b;
    Line(ll _k=0, ll _b=-INF): k(_k), b(_b) {}
    inline ll eval(int x) const { return k*(ll)x + b; }
};
 
// Li‐Chao tree with rollback support, domain x in [0..M]
struct LiChao {
    int M;
    vector<Line> st;
    vector<pair<int,Line>> hist;  // history of changes
 
    LiChao(int _M): M(_M), st(4*(M+1), Line()) {}
 
    // internal addLine with rollback
    void addLine(const Line &nw) { addLine(1,0,M,nw); }
 
    void addLine(int p, int l, int r, Line nw){
        int m = (l + r) >> 1;
        // ensure we record old st[p] before any modification
        bool leftBetter = nw.eval(l) > st[p].eval(l);
        bool midBetter  = nw.eval(m) > st[p].eval(m);
        if(midBetter){
            hist.emplace_back(p, st[p]);
            swap(nw, st[p]);
        }
        if(l == r) return;
        if(leftBetter != midBetter)
            addLine(p<<1,   l,   m, nw);
        else
            addLine(p<<1|1, m+1, r, nw);
    }
 
    ll query(int x) const { return query(1,0,M,x); }
    ll query(int p, int l, int r, int x) const {
        ll res = st[p].eval(x);
        if(l == r) return res;
        int m = (l + r) >> 1;
        if(x <= m) return max(res, query(p<<1,  l,  m, x));
        else        return max(res, query(p<<1|1,m+1,r,x));
    }
 
    // rollback to previous history size
    void rollback(int hsize){
        while((int)hist.size() > hsize){
            auto &pr = hist.back();
            st[pr.first] = pr.second;
            hist.pop_back();
        }
    }
};
 
// Segment‐tree of lines (each line active on [l..r])
struct SegTreeLines {
    int M;
    vector<vector<Line>> seg;
    SegTreeLines(int _M): M(_M), seg(4*(_M+1)) {}
 
    // insert a line active on [L..R]
    void insert(int L, int R, Line ln){ insert(1,0,M,L,R,ln); }
    void insert(int p, int l, int r, int L, int R, const Line &ln){
        if(R < l || r < L) return;
        if(L <= l && r <= R){
            seg[p].push_back(ln);
            return;
        }
        int m = (l + r) >> 1;
        insert(p<<1,   l,   m, L, R, ln);
        insert(p<<1|1, m+1, r, L, R, ln);
    }
};
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n, M; cin >> n >> M;
 
    SegTreeLines ST(M);
    FOR(_,0,n) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll k = (y2 - y1) / (x2 - x1);  // integer slope
        ll b = (ll)y1 - k*(ll)x1;
        ST.insert(x1, x2, Line(k,b));
    }
 
    vector<ll> ans(M+1, -1);
    LiChao lc(M);
 
    function<void(ll,ll,ll)> dfs = [&](ll p, ll l, ll r){
        ll h0 = lc.hist.size();
        // add all lines active on [l..r]
        for(const Line &ln : ST.seg[p]){
            lc.addLine(ln);
        }
        if(l == r){
            ll best = lc.query(l);
            if(best < -INF/2) best = -1;
            ans[l] = best;
        } else {
            ll m = (l + r) >> 1;
            dfs(p<<1,   l, m);
            dfs(p<<1|1, m+1, r);
        }
        // rollback LiChao modifications
        lc.rollback(h0);
    };
 
    dfs(1,0,M);
 
    for(int x = 0; x <= M; x++){
        cout << ans[x] << " ";
    }   cout << endl;
    return 0;
}