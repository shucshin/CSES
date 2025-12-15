#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll MOD = 1e9+7;
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S; cin >> S;
    int n = S.size();
 
    vector<ll> dp(n+1);
    dp[0] = 1;          // only the empty subsequence
    vector<int> last(26, 0);
 
    for(int i = 1; i <= n; i++){
        int c = S[i-1] - 'a';
        // double the count of subsequences by either taking or skipping S[i-1]
        dp[i] = dp[i-1] * 2 % MOD;
        // subtract those that we double‐counted: the ones that already
        // included a previous occurrence of S[i-1] as their “last pick”
        if(last[c] > 0){
            dp[i] = (dp[i] - dp[ last[c] - 1 ] + MOD) % MOD;
        }
        last[c] = i;
    }
 
    // subtract 1 to remove the empty subsequence
    ll ans = (dp[n] - 1 + MOD) % MOD;
    cout << ans << "\n";
 
    return 0;
}