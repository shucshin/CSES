#include <bits/stdc++.h>
using namespace std;
using ll = int;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll n, k1, k2;
// vector<int> AL[MXN];
vector<vi> AL;
vi removed(MXN, 0), sub(MXN, 0), frq(MXN, 0);
long long ans = 0;
 
struct Fenwick {
    int n; vector<int> bit;
    void init(int N) { n = N; bit.assign(n + 2, 0); }
    void upd(int i, int v) { for (; i <= n; i += i & -i) bit[i] += v; }
    int qry(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
    int range_qry(int l, int r) { if (l > r) return 0; if (r < 1) return 0; if (l < 1) l = 1; if (r > n) r = n; return qry(r) - qry(l - 1); }
} FT;
 
void get_size(int u, int p) {
    sub[u] = 1;
    for (int v : AL[u]) if (v != p && !removed[v]) {
        get_size(v, u);
        sub[u] += sub[v];
    }
}
 
int get_centroid(int u, int p, int tot) {
    for (int v : AL[u]) if (v != p && !removed[v]) {
        if (sub[v] > tot / 2) return get_centroid(v, u, tot);
    }
    return u;
}
 
void collect(int u, int p, int d, vector<int> &dst) {
    if (d > k2) return;
    dst.pb(d);
    for (int v : AL[u]) if (v != p && !removed[v]) collect(v, u, d + 1, dst);
}
 
void decompose(int entry) {
    get_size(entry, 0);
    int c = get_centroid(entry, 0, sub[entry]);
    removed[c] = 1;
 
    vector<int> touched; touched.reserve(sub[entry] + 1);
    // include centroid itself at distance 0
    if (frq[0] == 0) touched.pb(0);
    frq[0]++;
    FT.upd(1, 1);
 
    for (int v : AL[c]) if (!removed[v]) {
        vector<int> dst; dst.reserve(sub[v]);
        collect(v, c, 1, dst);
        for (int d : dst) {
            int l = k1 - d;
            if (l < 0) l = 0;
            int r = k2 - d;
            if (r >= 0 && l <= r) ans += FT.range_qry(l + 1, r + 1);
        }
        for (int d : dst) {
            if (d > k2) continue;
            if (frq[d] == 0) touched.pb(d);
            frq[d]++;
            FT.upd(d + 1, 1);
        }
    }
 
    for (int d : touched) { FT.upd(d + 1, -frq[d]); frq[d] = 0; }
 
    for (int v : AL[c]) if (!removed[v]) decompose(v);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k1 >> k2;
    AL.assign(n+1, {});
    FOR(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        AL[a].pb(b); AL[b].pb(a);
    }
    removed.assign(n+1, 0), sub.assign(n+1, 0), frq.assign(n+1, 0);
 
    FT.init(k2 + 2);
    decompose(1);
    cout << ans << endl;
    return 0;
}