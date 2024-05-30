#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

const ll MXN = 5e3+5;
const ll INF = 1e18;
ll dp[MXN][MXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    ll n = s.size(), m = t.size();
    FOR(i,0,n+1) FOR(j,0,m+1) dp[i][j] = INF;
    dp[0][0] = 0;
    
    FOR(i,0,n+1) FOR(j,0,m+1) {
        dp[i][j] = min( { dp[i][j], 
                         i ? dp[i-1][j]+1 : INF, 
                         j ? dp[i][j-1]+1 : INF,
                         i && j ? dp[i-1][j-1]+(s[i-1]!=t[j-1]) : INF
                        } );
    }
    cout << dp[n][m] << endl;
    return 0;
}