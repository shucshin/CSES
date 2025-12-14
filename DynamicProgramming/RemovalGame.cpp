#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()

const ll MXN = 5005;

ll dp[MXN][MXN];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n); for(auto &a : A) cin >> a;
    ll sum = accumulate(all(A), 0ll);
    
    FOR(i,0,n) dp[i][i] = A[i];
    RFOR(L,0,n) FOR(R,L+1,n) {
        // {L,R} goes from {n-1,n} | {n-2,n-1}, {n-2,n} | ... | {2,3},...,{2,n} | {1,2},...,{1,n}
        // Taking A[L], we subtract optimized (Y - X) for dp[L+1,R]
        // Taking A[R], we subtract optimized (Y - X) for dp[L,R-1]
        dp[L][R] = max(A[L] - dp[L+1][R], A[R] - dp[L][R-1]);
    }   cout << (sum + dp[0][n-1]) / 2 << endl;
    return 0;
}