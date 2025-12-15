#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll binpow(ll a, ll b) {
    ll r = 1; 
    while(b) {
	    if(b & 1ll) r *= a; 
	    a *= a; b >>= 1ll;
    } return r;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll ans = 0;
    FOR(b,0,60) {
        ll m = n + 1;
        ll k = m / binpow(2,b+1);
        ll r = m % binpow(2,b+1);
 
        ans += k * binpow(2,b);
        ans += max(0ll, r - binpow(2,b));
    }
 
    cout << ans << endl;
    return 0;
}