#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, b; cin >> n >> a >> b;
    vi A(n+1); FOR(i,1,n+1) cin >> A[i];
    vi pfx(n+1);
    partial_sum(A.begin(), A.end(), pfx.begin());
    ll ans = -INF;
 
    /* Maintain a deque of indices of size b-a+1 such that 
       pfx[j] values are in asc order in range [i-b,i-a]
    */
 
    deque<ll> dq;
    FOR(i,1,n+1) {
        if(i-a >= 0) {
            ll j = i-a;
            while(!dq.empty() && pfx[dq.back()] >= pfx[j]) dq.pop_back();
            dq.pb(j);
        }
        while(!dq.empty() && dq.front() < i - b) dq.pop_front(); // maintain range [i-b,i-a]
 
        if(!dq.empty()) ans = max(ans, pfx[i] - pfx[dq.front()]); // dq.front contains min pfx[i-b,i-a]
    }
    cout << ans << endl;
    
    return 0;
}