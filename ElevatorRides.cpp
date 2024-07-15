#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

pi dp[1 << 20]; // dp[mask] = {Rides, Accumulated Weight}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    vi W(n); FOR(i,0,n) cin >> W[i];
    dp[0] = {1,0}; // Ride 1 w/ no ppl
    FOR(mask, 1, (1 << n)) {
        dp[mask] = {30,0}; // High num to minimize
        FOR(i,0,n) {
            if(mask & (1 << i)) { // i-th person is included
                auto [r,w] = dp[mask ^ (1 << i)]; // Get result of subset excluding i-th person
                /* If adding weight of i-th person exceeds x, then add num of rides and 
                   update accumulated weight with min of w or W[i] since W[i] can be bigger 
                   than the accumulated weight w. Else just add W[i] to w since it's < x */
                (x < W[i] + w) ? (r++, w = min(w,W[i])) : w += W[i]; 
                dp[mask] = min(dp[mask], {r,w});
            }
        }
    }
    cout << dp[(1 << n) - 1].fst << endl;
    return 0;
}