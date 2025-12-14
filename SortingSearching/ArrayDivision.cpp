#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e18;
 
ll n, k;
vi A;
 
ll f(ll x) {
    ll cur = 0, subarrays = 1;
    for(auto a : A) {
        if(a > x) return INF;
        if(cur + a <= x) cur += a;
        else { cur = a; subarrays++; }
    }
    return subarrays;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    A.resize(n);
    FOR(i,0,n) cin >> A[i];
    ll sum = accumulate(all(A), 0ll);
 
    ll l = 0, r = sum, ans = INF;
    while(l <= r) {
        ll m = (l + r) >> 1;
        ll s = f(m);
        if(s <= k) {
            r = m-1;
            ans = min(ans, m);
        } else l = m+1;
    }
    cout << ans << endl;
 
    return 0;
}