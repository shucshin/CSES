#include <bits/stdc++.h>
using namespace std;
using lli = __int128;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
ll n;
vi A;
 
lli f(ll x) { // how many products in x time
    lli res = 0; // # of products
    FOR(i,0,n) {
        res += (x / A[i]);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> n >> t;
    A.resize(n);
    FOR(i,0,n) {
        cin >> A[i];
    }
 
    ll l = 0, r = 1e18, ans = INF;
    while(l <= r) {
        ll m = (l + r) >> 1;
        lli k = f(m); // products we made in m seconds
        if(k < t) {
            l = m+1;
        } else {
            r = m-1;
            ans = min(ans, m);
        }
    }
    cout << ans << endl;
    
    return 0;
}