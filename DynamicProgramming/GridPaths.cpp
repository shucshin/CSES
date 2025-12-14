#include <bits/stdc++.h>
using namespace std;
using ll = long long; // %lld
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

const ll MOD = 1e9+7;

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<string> grid(n); FOR(i,0,n) cin >> grid[i];
    vector<vi> dp(n,vi(n,0)); dp[0][0] = 1;
    FOR(i,0,n) {
        FOR(j,0,n) {
            if(grid[i][j]=='*') {dp[i][j] = 0; continue;}
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
            if(dp[i][j] < 0) dp[i][j] += MOD;
        } 
    }
    cout << dp[n-1][n-1] << endl;    
    return 0;
}