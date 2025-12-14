#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MOD = 1e9+7;
const ll MXN = 1e5+5;
const ll MXM = 105;

ll dp[MXN][MXM];
 
/* Array of n elems w/ each elem in range [1,m], abs diff between adjacent vals is at most 1
   If A[i] = 0, then it can be any value from [1,m]. Count # of arrays that match this.
   MXN = 1e5, m <= 100. dp[i][j] = # of ways to have A[i] = j
   Note that the transition is sum of the possible values from the past index, which are [j-1,j+1] 
   dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
*/
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof dp);
    ll n, m; cin >> n >> m;
    vi A(n); for(auto &a : A) cin >> a;
 
 
    if(!A[0]) { // for all values [1,m] there is 1 way
    FOR(j,1,m+1) dp[0][j]    = 1;
    } else       dp[0][A[0]] = 1; // 1 way for only A[0]
 
    FOR(i,1,n) { 
        if(!A[i]) {
            FOR(j,1,m+1) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
            }
        } else {
            dp[i][A[i]] = (dp[i-1][A[i]-1] + dp[i-1][A[i]] + dp[i-1][A[i]+1]) % MOD;
        }
    }
 
    ll ans = 0; // sum # of ways of putting any value in last index
    FOR(j,1,m+1) ans = (ans + dp[n-1][j]) % MOD;
    cout << ans << endl;
 
    return 0;
}