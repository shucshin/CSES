#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<string> grid(n);
    FOR(i,0,n) cin >> grid[i];
 
    if(n == 1) { // Edge case
        cout << grid[0][0] << endl;
        return 0;
    }
 
    vector<vi> vis(n,vi(n,0));
    vector<pi> dp, ndp; // dp is list of positions of cur len w/ minimal string
    dp.emplace_back(0,0);
    string ans = string(1, grid[0][0]);
    ll t = 2*n - 2;
    FOR(_,0,t) {
        ndp.clear();
        for(auto [i,j] : dp) { // process right/down
            if(i+1 < n && !vis[i+1][j]) {
                vis[i+1][j] = 1;
                ndp.emplace_back(i+1, j);
            }
            if(j+1 < n) {
                vis[i][j+1] = 1;
                ndp.emplace_back(i, j+1);
            }
        }
 
        // Find minimal letter
        char best = 'Z'+1;
        for(auto [i,j] : ndp) {
            best = min(best, grid[i][j]);
        }
 
        // build dp for next length min str
        dp.clear();
        for(auto [i,j] : ndp) {
            if(grid[i][j] == best) dp.emplace_back(i,j);
        }
 
        ans.pb(best);
    }
 
    cout << ans << endl;
 
    return 0;
}