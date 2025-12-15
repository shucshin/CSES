#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, y; cin >> n;
    ll mx1 = -INF, mn1 = INF;
    ll mx2 = -INF, mn2 = INF;
 
    FOR(i,0,n) { cin >> x >> y;
        ll s = x + y;
        ll d = x - y;
 
        mx1 = max(mx1, s);
        mn1 = min(mn1, s);
        mx2 = max(mx2, d);
        mn2 = min(mn2, d);
        
        ll ans = max(mx1 - mn1, mx2 - mn2);
        cout << ans << endl;
    }
 
    return 0;
}