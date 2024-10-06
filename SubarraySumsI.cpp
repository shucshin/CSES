#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, a, sum = 0, ans = 0; cin >> n >> x;
    map<ll,ll> m;
    FOR(_,0,n) {
        cin >> a;
        sum += a;
        if(sum == x) ans++;
        ans += m[sum-x];
        m[sum]++;
    }   cout << ans << endl;

    return 0;
}