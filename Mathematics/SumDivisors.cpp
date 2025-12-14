#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = __int128;

#define endl '\n'

const ll MOD = 1e9+7;
 
ll mul(ll a, ll b) {
    return (ll)(((lli)a * b) % MOD);
}
 
//==Sum from a to b w/ MOD==
ll gauss_mod(ll a, ll b) {
    ll p = b - a + 1, q = a + b;
    p % 2 ? q /= 2 : p /= 2;
    return (lli)p * q % MOD;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll ans = 0, l = 1;
    while(l <= n) {
        ll q = n / l; 
        ll r = n / q;
        ll add = mul(gauss_mod(l, r), q % MOD);
        ans = (ans + add) % MOD;
        l = r + 1;
    }
    cout << ans << endl;
    return 0;
}