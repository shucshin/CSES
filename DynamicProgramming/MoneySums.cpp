#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll MXN = 105;
const ll MXS = 1e5+5;

ll dp[MXN][MXS];
 
/* Given n coins with values, find all money sums that can be created.
   MXN = 100, coin <= 1000
   dp[i][j] = can i make sum j w/ first i coins?
*/
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof dp);
    ll n; cin >> n;
    vi coin(n); for(auto &c : coin) cin >> c;
    ll sum = accumulate(all(coin), 0ll);
 
    dp[0][0] = 1;
    FOR(i,1,n+1) {
        FOR(j,0,sum+1) {
            dp[i][j] = dp[i-1][j];
            if(j - coin[i-1] >= 0) {
                dp[i][j] |= dp[i-1][j-coin[i-1]];
            }
        }
    }
 
    vi ans;
    FOR(x,1,sum+1) {
        if(dp[n][x]) ans.pb(x);
    } 
 
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " "; cout << endl;
 
    return 0;
}