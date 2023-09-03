#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long; // %lld
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define ub(v,a) upper_bound(all(v),a)-v.begin()
const ll INF = 1e9;

ll LIS(vi &A) {
    int n = A.size(); vi dp(n+1,INF); dp[0] = -INF;
    FOR(i,0,n) {
        int l = ub(dp,A[i]);
        if(dp[l-1] < A[i] && A[i] < dp[l]) dp[l] = A[i];
    }
    int ans = 0;
    FOR(i,0,n+1) if(dp[i] < INF) ans = i;
    return ans;
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
    cout << LIS(A) << endl;
    return 0;
}
