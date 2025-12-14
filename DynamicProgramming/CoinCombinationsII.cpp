//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long; // %lld
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll MOD = 1e9+7;

// g++ A.cpp -o A && ./A < input.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, x; cin >> n >> x;
    vi coin(n); FOR(i,0,n) cin >> coin[i];
    vi dp(x+1); dp[0] = 1;
    FOR(i,0,n) {
        FOR(j,coin[i],x+1) {
            dp[j] += dp[j-coin[i]];
            dp[j] %= MOD;
            if(dp[j] < 0) dp[j] += MOD;
        }
    }
    cout << dp[x] << endl;
    return 0;
}