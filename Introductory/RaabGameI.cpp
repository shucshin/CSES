#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
void solve() {
    ll n, a, b; cin >> n >> a >> b;
    ll m = a + b;
    if (m > n || (m > 0 && (a == 0 || b == 0))) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vi A, B; A.reserve(n); B.reserve(n);
    if (m == 0) {
        FOR(i,1,n+1) { A.pb(i); B.pb(i); }
    } else {
        // Both a,b > 0: use rotation inside first m positions
        FOR(i,1,m+1) A.pb(i);
        // Q[i] = i + a (wrap to [1..m])
        FOR(i,1,m+1) {
            ll q = i + a; if (q > m) q -= m; B.pb(q);
        }
        // Append ties
        FOR(i,m+1,n+1) { A.pb(i); B.pb(i); }
    }
    
    FOR(i,0,n) { if(i) cout << " "; cout << A[i]; } cout << endl;
    FOR(i,0,n) { if(i) cout << " "; cout << B[i]; } cout << endl;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}