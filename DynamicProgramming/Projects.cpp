#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
/* Given starting day, ending day and reward (a, b, p) for each project
   and given that you can't attend 2 projects on the same day.
   Maximize reward. MXN = 2e5, a,b,p <= 1e9
 
   Compress the days, we only care about the days we use. Max # of days will be 4e5
   dp[i] = Max reward before day i
   dp[i] = dp[i-1] // reward is accumating
   dp[i] = dp[start date of project] + reward
*/
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n), B(n), P(n);
    map<ll,ll> cmp;
    FOR(i,0,n) {
        cin >> A[i] >> B[i] >> P[i];
        B[i]++; // add 1 to avoid intersection
        cmp[A[i]], cmp[B[i]];
    }
 
    ll c = 0;
    for(auto &[k,v] : cmp) {
        v = c++; // compressed index for orginal day k
    }
 
    vector<vector<pi>> project(c);
    FOR(i,0,n) { // for each ending day of project put starting date and reward
        project[cmp[B[i]]].pb({cmp[A[i]], P[i]});
    }
 
    vi dp(c, 0);
    FOR(i,0,c) {
        if(i) dp[i] = dp[i-1];
        // project[i] = i-th ending date, so we check the dp of all starting dates and its reward 
        for(auto &[k,v] : project[i]) { // k = starting date, v = reward
            dp[i] = max(dp[i], dp[k] + v);
        }
    }
    cout << dp[c-1] << endl;
 
    return 0;
}