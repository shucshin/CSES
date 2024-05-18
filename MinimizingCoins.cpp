#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll MXN = 1e6+5;
const ll INF = 1e18;

ll n, x, dp[MXN];
vi A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n >> x; A.resize(n);
    FOR(i,0,x+1) dp[i] = INF;
    FOR(i,0,n) {
        cin >> A[i];
        dp[A[i]] = 1;
    }
    FOR(i,1,x+1) {
        for(auto a : A) {
            if(i-a > 0) {
                dp[i] = min(dp[i], dp[i-a]+1);
            }
        }
    }
    cout << ((dp[x]==INF) ? -1 : dp[x]) << endl;
    return 0;
}