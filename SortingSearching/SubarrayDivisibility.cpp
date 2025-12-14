#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
 
    map<ll,ll> mp;
    ll ans = 0, cur = 0;
    for(auto a : A) {
        cur = (cur + a) % n;
        if(!cur) ans++;
        ans += mp[cur];
        ans += (cur > 0 ? mp[cur-n] : mp[n+cur]);
        mp[cur]++;
    } 
    cout << ans << endl;
    return 0;
}