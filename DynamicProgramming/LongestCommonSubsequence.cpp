#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
//==Longest Common Subsequence==
vi LCS(vi &s, vi &t) {
    ll n = s.size(), m = t.size();
    vector<vi> dp(n+1, vi(m+1, 0));
    FOR(i,1,n+1) FOR(j,1,m+1) {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // Pull from up or left from table
        if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1; // Sequence Length ++
    }
    vi lcs; ll i = n, j = m; 
    while(i && j) {
        if(s[i-1] == t[j-1]) lcs.pb(s[i-1]), i--, j--;
        else      dp[i][j-1] < dp[i-1][j] ? i-- : j--;
    } 
    reverse(all(lcs));
    return lcs;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vi a(n), b(m);
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,m) cin >> b[i];
 
    vi lcs = LCS(a, b);
 
    cout << lcs.size() << endl;
    for(auto x : lcs) cout << x << " "; cout << endl;
 
    return 0;
}