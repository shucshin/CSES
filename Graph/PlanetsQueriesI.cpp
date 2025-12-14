#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vector<vi> up;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    up.assign(32,vi(n));
    vi t(n); FOR(i,0,n) { cin >> t[i]; t[i]--; }
    FOR(u,0,n) up[0][u] = t[u];
 
    FOR(i,1,32) FOR(u,0,n) {
        ll p = up[i-1][u];
        up[i][u] = up[i-1][p];
    }
 
    auto jump = [&](ll x, ll d) {
        FOR(i,0,32) { if ((d >> i) & 1) x = up[i][x]; }
        return x;
    };
 
    ll v, k;
    while(q--) {
        cin >> v >> k; --v;
        cout << jump(v, k) + 1 << endl;
    }
 
    return 0;
}