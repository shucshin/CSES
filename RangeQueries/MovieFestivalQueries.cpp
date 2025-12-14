#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vector<pi> seg(n);
    ll mx = 0;
    FOR(i,0,n) { 
        cin >> seg[i].fst >> seg[i].snd; 
        mx = max(mx, seg[i].snd); 
    }
    vector<pi> ask(q);
    FOR(i,0,q) { 
        cin >> ask[i].fst >> ask[i].snd; 
        mx = max(mx, ask[i].snd); 
    }
 
    // Build next time for each t: next[t] = earliest finishing time among 
    // movies with start >= t, or mx+1 if none
    sort(all(seg), [](const pi& a, const pi& b){ 
        if (a.fst != b.fst) return a.fst < b.fst; 
        return a.snd < b.snd; 
    });
 
    vi nxt0(mx + 2, mx+1);
    priority_queue<ll, vector<ll>, greater<ll>> pq; // ends min-heap
    ll p = (ll)seg.size() - 1;
    for (ll t = mx; t >= 1; --t) {
        while (p >= 0 && seg[p].fst == t) { 
            pq.push(seg[p].snd); --p; 
        }
        while (!pq.empty() && pq.top() < t) pq.pop(); // (not strictly needed, but safe)
        nxt0[t] = pq.empty() ? mx+1 : pq.top();
    }
    nxt0[mx+1] = mx+1;
 
    // Binary lifting over time states
    ll K = 1; while ((1LL << K) <= mx+1) K++;
    vector<vi> up(K, vi(mx + 2, mx+1));
    FOR(t,1,mx+2) up[0][t] = (t <= mx ? nxt0[t] : mx+1);
    FOR(k,1,K) {
        FOR(t,1,mx+2) up[k][t] = up[k-1][ up[k-1][t] ];
    }
 
    // Answer queries
    FOR(i,0,q) {
        ll a = ask[i].fst, b = ask[i].snd;
        if (a > mx) { cout << 0 << endl; continue; }
        ll cur = a, ans = 0;
        for (ll k = K - 1; k >= 0; --k) {
            if (up[k][cur] <= b) { ans += (1LL << k); cur = up[k][cur]; }
        }
        cout << ans << endl;
    }
    return 0;
}