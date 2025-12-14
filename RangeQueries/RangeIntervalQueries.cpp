#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
#define LSOne(a) ((a) & -(a))
struct Fenwick {
    ll n; vi bit; // Binary Indexed Tree
    Fenwick() {}
    Fenwick(ll N): n(N), bit(n+1, 0) {}
    void add(ll i, ll v) { for(; i <= n; i += LSOne(i)) bit[i] += v; }
    ll query(ll i) { ll s = 0; for(; i > 0; i -= LSOne(i)) s += bit[i]; return s; }
    ll query(ll l, ll r) { if (l > r) return 0; return query(r) - query(l-1); }
};
 
struct PartQ { ll a, b, t, id, sgn; };
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vi A(n+1); FOR(i,1,n+1) cin >> A[i];
 
    vector<pi> pts;
    FOR(i,1,n+1) pts.pb({A[i], i});
    sort(all(pts));
 
    vector<PartQ> qs; qs.reserve(2*q);
    FOR(i,0,q) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        qs.pb({a,b,d,i,+1});
        qs.pb({a,b,c-1,i,-1});
    }
    sort(all(qs), [&](const PartQ &x, const PartQ &y){ return x.t < y.t; });
 
    Fenwick ft(n);
    vi ans(q, 0);
 
    ll p = 0; // pointer in pts (sorted by value ascending)
    for (auto &qq : qs) {
        while(p < pts.size() && pts[p].fst <= qq.t) {
            ft.add(pts[p].snd, 1);
            p++;
        }
        ans[qq.id] += qq.sgn * ft.query(qq.a, qq.b);
    }
 
    FOR(i,0,q) cout << ans[i] << endl;
    return 0;
}