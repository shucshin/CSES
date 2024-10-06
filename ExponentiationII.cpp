#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const ll MOD = 1e9+7;

ll bcpow(ll a, ll b, ll m=MOD) {
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, b, c; cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        cout << bcpow(a,bcpow(b,c,MOD-1)) << endl;
    }
    return 0;
}