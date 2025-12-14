#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MXN = 505;
const ll INF = 1e18;

ll dp[MXN][MXN];
 
/* Given a x b rectangle, minimize cuts to make all squares. a,b <= 500
   dp[a][b] = min # of cuts to cut i x j into squares
*/
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    FOR(i,0,MXN) FOR(j,0,MXN) dp[i][j] = INF;
    ll a, b; cin >> a >> b;
 
    FOR(i,0,a+1) FOR(j,0,b+1) {
        if(i == j) { // already square, need 0
            dp[i][j] = 0;
            continue;
        }
 
        FOR(k,1,j) { // All possible horizontal cuts
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
 
        FOR(k,1,i) { // All possible vertical cuts
            dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
        }
    }
    cout << dp[a][b] << endl;
 
    return 0;
}