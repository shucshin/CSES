#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
const ll MXN = 5e2+5;
const ll MXS = (MXN*(MXN+1))/2;
const ll MOD = 1e9+7;

ll n, S, dp[MXN+1][MXS+1];

ll f(ll i, ll sum) {
    if(sum > S/2) return 0;
    if(i == n) {
        if(sum == S/2) return 1;
        else return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = (f(i+1,sum+i) + f(i+1,sum))%MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    memset(dp,-1,sizeof(dp));
    S = (n*(n+1))/2;
    if(S%2) {
        cout << 0 << endl;
        return 0;
    }
    f(1,0); // Es lo mismo que imprimir dp[1][0]
    cout << dp[1][0] << endl;
    return 0;
}