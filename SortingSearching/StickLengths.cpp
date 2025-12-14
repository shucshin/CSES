#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n);
    FOR(i,0,n) cin >> A[i];

    auto cost = [&](ll x) {
        ll sum = 0;
        for(auto a : A) sum += abs(a-x);
        return sum;
    };

    ll l = 0, r = 1e9, ans = INF;
    while(r-l > 3) {
        ll m1 = l+(r-l)/3, m2 = r-(r-l)/3;
        ll a = cost(m1), b = cost(m2);
        a > b ? l = m1+1 : r = m2-1; // < max, > min
    } 
    FOR(m,l,r+1) {
        ans = min(ans,cost(m));
    }
    cout << ans << endl;

    return 0;
}