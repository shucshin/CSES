#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, d; cin >> n;
    vector<pi> A(n);
    FOR(i,0,n) {
        cin >> a >> d;
        A[i] = {a, d};
    }   sort(all(A));
    
    ll t = 0, ans = 0;
    FOR(i,0,n) {
        tie(a, d) = A[i];
        t += a;
        ans += (d - t);
    }
    cout << ans << endl;
 
    return 0;
}