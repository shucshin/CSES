#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
    sort(all(A));
    ll mx = A.back();
    ll ans = accumulate(all(A), 0ll);
    ll sum = ans - mx;
    if(mx > sum) ans += (mx - sum);
 
    cout << ans << endl;
    return 0;
}