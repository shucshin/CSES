#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
 
const ll MOD = 1e9+7;
const ll MXN = 505;
 
ll bcpow(ll a, ll b, ll m=MOD) {
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}
 
vi fac(1005), inv(1005);
void facinv() {
    fac[0] = 1; fac[1] = 1;
    FOR(i,2,MXN) fac[i] = fac[i-1]*i%MOD; 
    inv[MXN-1] = bcpow(fac[MXN-1], MOD-2);
    for(ll i = MXN-2; i >= 0; i--) inv[i] = inv[i+1]*(i+1ll)%MOD;
} 
 
ll nCk(ll n, ll k) {
    return n < k ? 0 : fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}
 
ll dp[MXN][MXN];
string s;
 
ll f(ll l, ll r) {
    if(l == r)         return 0; // Substring size 1, can't del
    if(l >  r)         return 1; // Substring size 0
    if(l+1 == r)       return s[l] == s[r]; // Substring size 2, check if equal
    if(dp[l][r] != -1) return dp[l][r];
 
    ll res = 0;
    for(int m = l+1; m <= r; m++) {
        if(s[l] == s[m]) {
            if(m == r) {
                // Can't divide range so just calc [l+1,r-1]
                res = (res + f(l+1,m-1)) % MOD;
                continue;
            }
            ll x = (m-l+1)/2; // [l,m]
            ll y = (r-m)/2;  // [m+1,r]
            res = (res + ((f(l+1,m-1) * f(m+1,r) % MOD) * nCk(x+y,x)) % MOD) % MOD;
            /* Principio de Multiplicacion :: f(l+1,m-1) maneras de hacer el rango [l+1,m-1] y 
                                              f(m+1,r)   maneras de hacer el rango [m+1,r] 
                                              Stars and Bars de x elems en x+y espacios */
        }
    }   
    return dp[l][r] = res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    facinv();
    memset(dp,-1,sizeof dp);
    cin >> s;
    cout << f(0,s.size()-1) << endl;
 
    return 0;
}