#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, mx = 0; cin >> n;
    vi A(n);
    FOR(i,0,n) { 
        cin >> A[i]; 
        mx = max(mx, A[i]);
    }
 
    vi cnt(mx+1, 0);
    for(auto a : A) cnt[a]++;
 
    ll ans = 1;
    RFOR(d,1,mx+1) { // check divisors
        ll c = 0;
        for(ll m = d; m <= mx; m += d) {
            c += cnt[m]; // are there multiples of d
            if(c >= 2) break;
        }
        if(c >= 2) { ans = d; break; }
    }
    cout << ans << endl;
    return 0;
}