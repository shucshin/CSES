#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll MXN = 2e6+5;
const ll MOD = 1e9+7;

vi fac(MXN), inv(MXN);

ll bcpow(ll a, ll b, ll m=MOD){
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}

void facinv() {
    fac[0] = 1; fac[1] = 1;
    FOR(i,2,MXN) fac[i] = fac[i-1]*i%MOD; 
    inv[MXN-1] = bcpow(fac[MXN-1], MOD-2);
    for(ll i = MXN-2; i >= 0; i--) inv[i] = inv[i+1]*(i+1ll)%MOD;
} 

ll nCk(ll n, ll k) {
    return n < k ? 0 : fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a, b; cin >> n;
    facinv();
    FOR(_,0,n) {
        cin >> a >> b;
        cout << nCk(a,b) << endl;
    }
    return 0;
}