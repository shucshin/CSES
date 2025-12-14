#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll subarraySum(vi &A, ll k) {
    map<ll,ll> m;
    ll ans = 0, cur = 0;
    FOR(i,0,A.size()) {
        cur += A[i];
        if(cur == k) ans++;
        if(m.count(cur - k)) ans += m[cur-k];
        m[cur]++;
    } return ans;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    vi A(n); FOR(i,0,n) cin >> A[i];
    cout << subarraySum(A, x) << endl;
 
    return 0;
}