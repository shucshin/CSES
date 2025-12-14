#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long; // %lld
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define lb(v,a) lower_bound(all(v),a)-v.begin()
const ll INF = 1e9;

ll LIS(vi &A) {
    vi dp;
    for(auto x : A) {
        ll i = lb(dp,x);
        if (i==dp.size()) (dp.pb(x));
        else dp[i] = x;
    }
    return dp.size();
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
