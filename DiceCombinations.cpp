//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long; // %lld
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll MOD = 1e9+7;

// g++ A.cpp -o A && ./A < input.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi dp(n+1,0); dp[0] = 1;
    FOR(i,1,n+1) {
        FOR(j,1,7) {
            if(i < j) break;
            dp[i] += dp[i-j]%MOD;
            dp[i] %= MOD;
            if(dp[i] < 0) dp[i] += MOD;    
        }
    }
    cout << dp[n] << endl;
    return 0;
}