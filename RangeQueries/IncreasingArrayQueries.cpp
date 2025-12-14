#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MXN = 2e5+5;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vi x(n+1), pref(n+1,0);
    FOR(i,1,n+1) {
        cin >> x[i];
        pref[i] = pref[i-1] + x[i];
    }
 
    // Next greater or equal to the right
    vi R(n+2, n+1), st;
    for (ll i = 1; i <= n; i++) {
        while (!st.empty() && x[st.back()] <= x[i]) {
            R[st.back()] = i; st.pop_back();
        }
        st.pb(i);
    }
    while (!st.empty()) { R[st.back()] = n+1; st.pop_back(); }
 
    const int K = 20;
    static ll up[K][MXN];
    static ll add[K][MXN];
 
    for (ll i = 1; i <= n; i++) {
        up[0][i] = (R[i] <= n ? R[i] : 0);
        ll to = R[i] - 1; // segment (i, R[i]) exclusive of R[i]
        add[0][i] = (to - i) * x[i] - (pref[to] - pref[i]);
    }
    for (int k = 1; k < K; k++) {
        for (ll i = 1; i <= n; i++) {
            up[k][i] = up[k-1][ up[k-1][i] ];
            add[k][i] = add[k-1][i] + add[k-1][ up[k-1][i] ];
        }
    }
 
    while(q--) {
        ll l, r; cin >> l >> r;
        ll ans = 0;
        ll cur = l;
        for (int k = K-1; k >= 0; k--) {
            if (up[k][cur] != 0 && up[k][cur] <= r) {
                ans += add[k][cur];
                cur = up[k][cur];
            }
        }
        // tail (cur, r]: raise to x[cur]
        ans += (r - cur) * x[cur] - (pref[r] - pref[cur]);
        cout << ans << endl;
    }
    return 0;
}