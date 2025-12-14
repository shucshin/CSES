#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
struct Q { ll l, r, id; };
 
// Distinct Values Queries
void solve() {
    ll n, q; cin >> n >> q;
    vi A(n); FOR(i,0,n) cin >> A[i];
 
    // Coordinate compression (generic for freq-based Mo)
    auto comp = A; sort(all(comp)); comp.erase(unique(all(comp)), comp.end());
    FOR(i,0,n) A[i] = lower_bound(all(comp), A[i]) - comp.begin();
    ll m = comp.size();
 
    vector<Q> queries(q);
    FOR(i,0,q) {
        ll l, r; cin >> l >> r; --l; --r; // 0-indexed inclusive
        queries[i] = {l, r, i};
    }
 
    ll B = max(1LL, (ll)sqrt(max(1LL, n)));
    auto cmp = [&](const Q &a, const Q &b) {
        ll ba = a.l / B, bb = b.l / B;
        if(ba != bb) return ba < bb;
        if(ba & 1) return a.r > b.r; // zig-zag to reduce moves
        return a.r < b.r;
    };
    sort(all(queries), cmp);
 
    vi frq(m, 0);
    vector<ll> ans(q, 0);
    ll cur = 0; // example: number of distinct elements in current window
 
    auto add = [&](ll pos) {
        ll v = A[pos];
        if(frq[v] == 0) cur++;
        frq[v]++;
    };
    auto remove = [&](ll pos) {
        ll v = A[pos];
        frq[v]--;
        if(frq[v] == 0) cur--;
    };
 
    ll L = 0, R = -1; // current window [L, R]
    FOR(i,0,q) {
        auto &qq = queries[i];
        while(L > qq.l) add(--L);
        while(R < qq.r) add(++R);
        while(L < qq.l) remove(L++);
        while(R > qq.r) remove(R--);
        ans[qq.id] = cur;
    }
 
    FOR(i,0,q) cout << ans[i] << endl;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}