#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, sum = 0, ans = -INF;
    cin >> n;
    FOR(_,0,n) {
        cin >> a;
        sum += a;
        ans = max(ans,sum);
        if(sum < 0) sum = 0;
    }   cout << ans << endl;
    return 0;
}