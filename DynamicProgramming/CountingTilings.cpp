#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back

const ll MOD = 1e9+7;
 
/* Count # of ways to fill n x m grid using 1 x 2 and 2 x 1 tiles.
   n <= 10, m <= 1000
*/
 
ll n, m, dp[1005][(1 << 12)];
 
// Generate all possible masks - all possble states given the cur mask
void gen_nxt_mask(ll i, ll cur_mask, ll nxt_mask, vi &A) {
    if(i == n+1) { A.pb(nxt_mask); return; }
    if(cur_mask & (1 << i)) {
        gen_nxt_mask(i+1, cur_mask, nxt_mask, A);
    }
    if(i != n)  {
        if(!(cur_mask & (1 << i)) and !(cur_mask & (1 << (i+1)))) {
            gen_nxt_mask(i+2, cur_mask, nxt_mask, A);
        }
    }
 
    if(!(cur_mask & (1 << i))) {
        gen_nxt_mask(i+1, cur_mask, nxt_mask + (1 << i), A);
    }
}
 
ll f(ll c, ll mask) {
    if(c == (m+1)) { // check that block doesn't go out of bounds
        if(!mask) return 1;
        return 0;
    }
 
    if(dp[c][mask] != -1) return dp[c][mask];
    ll ans = 0;
    vi A;
    gen_nxt_mask(1, mask, 0, A);
 
    // Try all possible masks for the cur column
    for(auto msk : A) {
        ans = (ans + f(c+1, msk)) % MOD;
    }
    A.clear();
    return dp[c][mask] = ans;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cout << f(1, 0) << endl;
 
    return 0;
}