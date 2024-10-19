#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define ub(A,a) upper_bound(all(A),a)-A.begin()

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, ans = 0; cin >> n;
    vi A(n,INF); A[0] = -INF;
    FOR(_,0,n) {
        cin >> a;
        ll i = ub(A,a);
        A[i] = min(A[i],a);
        ans = max(ans,i);
    }
    cout << ans << endl;
    return 0;
}