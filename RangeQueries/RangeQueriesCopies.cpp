#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
class Segtree {
private:
struct node { ll x = 0; ll l = 0, r = 0; node(){}; };
    ll new_node() { st.pb(node()); return (ll)st.size() - 1; }
 
    ll build(ll L, ll R) {
        ll p = new_node();
        if (L == R) { st[p].x = A[L]; return p; }
        ll m = (L + R) >> 1;
        ll lc = build(L, m);
        ll rc = build(m + 1, R);
        st[p].l = lc; st[p].r = rc;
        st[p].x = st[lc].x + st[rc].x;
        return p;
    }
 
    ll upd(ll prev, ll L, ll R, ll i, ll val) {
        ll p = new_node();
        st[p] = st[prev];
        if (L == R) { st[p].x = val; return p; }
        ll m = (L + R) >> 1;
        if (i <= m) st[p].l = upd(st[prev].l, L, m, i, val);
        else         st[p].r = upd(st[prev].r, m + 1, R, i, val);
        st[p].x = st[st[p].l].x + st[st[p].r].x;
        return p;
    }
 
    ll query(ll p, ll L, ll R, ll i, ll j) {
        if (!p || j < L || R < i) return 0;
        if (i <= L && R <= j) return st[p].x;
        ll m = (L + R) >> 1;
        return query(st[p].l, L, m, i, j) + query(st[p].r, m + 1, R, i, j);
    }
 
public:
    ll n; vi A; vector<node> st;
    Segtree(ll sz) : n(sz), A(n+1) { st.reserve((size_t)n * 25 + 10); st.pb(node()); }
    ll build() { return build(1, n); }
    ll upd(ll root, ll i, ll val) { return upd(root, 1, n, i, val); }
    ll query(ll root, ll i, ll j) { return query(root, 1, n, i, j); }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    Segtree st(n);
    FOR(i,1,n+1) cin >> st.A[i];
 
    ll root0 = st.build();
    vi root; root.pb(0); // 1-based version ids
    root.pb(root0);
 
    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll k, a, x; cin >> k >> a >> x;
            ll newRoot = st.upd(root[k], a, x);
            root[k] = newRoot;
        } else if (t == 2) {
            ll k, a, b; cin >> k >> a >> b;
            cout << st.query(root[k], a, b) << endl;
        } else { // t == 3
            ll k; cin >> k;
            root.pb(root[(int)k]);
        }
    }
    return 0;
}