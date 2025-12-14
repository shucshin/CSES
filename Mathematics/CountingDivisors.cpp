#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll MXN = 1e6+5;

ll numberOfDivisors(ll n) {
    ll ans = 1;
    for(ll i = 2; (ll)i*i <= n; i++) {
        if(n%i==0) {
            ll e = 0;
            do {e++; n /= i;} while (n%i==0);
            ans *= e+1;
        }
    }
    if(n > 1) ans *= 2;
    return ans;
}

int main() {
    ll n, x; cin >> n;
    vi dp(MXN,-1);
    FOR(_,0,n) {
        cin >> x;
        if(dp[x] != -1) cout << dp[x] << endl;
        else {
            ll d = numberOfDivisors(x);
            dp[x] = d; 
            cout << d << endl;
        }
    }
    return 0;
}