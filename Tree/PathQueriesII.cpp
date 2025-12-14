#include <bits/stdc++.h>
using namespace std;
using ll = int;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e9;
 
// HLD + Segment Tree (max), point update
class Segtree {
private:
    struct node { ll x = -INF; node(){}; };
    ll l(ll p) { return (p << 1); }
    ll r(ll p) { return (p << 1) | 1; }
    void merge(ll p) { st[p].x = max(st[l(p)].x, st[r(p)].x); }
    void build(ll p, ll L, ll R) {
        if (L == R) { st[p].x = A[L]; return; }
        ll m = (L + R) >> 1;
        build(l(p), L, m);
        build(r(p), m+1, R);
        merge(p);
    }
    void upd(ll p, ll L, ll R, ll i, ll val) {
        if (i < L || i > R) return;
        if (L == R) { st[p].x = val; return; }
        ll m = (L + R) >> 1;
        if (i <= m) upd(l(p), L, m, i, val);
        else        upd(r(p), m+1, R, i, val);
        merge(p);
    }
    ll query(ll p, ll L, ll R, ll i, ll j) {
        if (i > R || j < L)  return -INF;
        if (i <= L && R <= j) return st[p].x;
        ll m = (L + R) >> 1;
        return max(query(l(p), L, m, i, j), query(r(p), m+1, R, i, j));
    }
public:
    ll n; vi A; vector<node> st;
    Segtree() : n(0) {}
    Segtree(ll sz) : n(sz), A(n+1, -INF), st(4*n+5) {}
    void init(ll sz) { n = sz; A.assign(n+1, -INF); st.assign(4*n+5, node()); }
    void build() { build(1, 1, n); }
    void upd(ll i, ll val) { upd(1, 1, n, i, val); }
    ll query(ll i, ll j) { return query(1, 1, n, i, j); }
} ST;
 
ll n, q;
vector<vi> AL;
vi val, par, depth, heavy, head, pos, sz;
ll cur_pos = 0;
 
ll dfs_sz(ll u, ll p) {
    par[u] = p;
    depth[u] = (p == -1 ? 0 : depth[p] + 1);
    sz[u] = 1;
    ll max_sz = 0;
    for (auto &v : AL[u]) if (v != p) {
        ll s = dfs_sz(v, u);
        sz[u] += s;
        if (s > max_sz) { max_sz = s; heavy[u] = v; }
    }
    return sz[u];
}
 
void dfs_decompose(ll u, ll h) {
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1) dfs_decompose(heavy[u], h);
    for (auto &v : AL[u]) if (v != par[u] && v != heavy[u]) dfs_decompose(v, v);
}
 
ll query_path(ll a, ll b) {
    ll res = -INF;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, ST.query(pos[ head[a] ] + 1, pos[a] + 1));
        a = par[ head[a] ];
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, ST.query(pos[a] + 1, pos[b] + 1));
    return res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    val.assign(n, 0);
    FOR(i,0,n) cin >> val[i];
    AL.assign(n, {});
    FOR(i,0,n-1) {
        ll a, b; cin >> a >> b; --a; --b;
        AL[a].pb(b); AL[b].pb(a);
    }
 
    par.assign(n, -1);
    depth.assign(n, 0);
    heavy.assign(n, -1);
    head.assign(n, 0);
    pos.assign(n, 0);
    sz.assign(n, 0);
    cur_pos = 0;
 
    dfs_sz(0, -1);
    dfs_decompose(0, 0);
 
    ST.init(n);
    FOR(u,0,n) ST.A[pos[u] + 1] = val[u];
    ST.build();
 
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll s, x; cin >> s >> x; --s;
            val[s] = x;
            ST.upd(pos[s] + 1, x);
        } else {
            ll a, b; cin >> a >> b; --a; --b;
            cout << query_path(a, b) << ' ';
        }
    }
    return 0;
}