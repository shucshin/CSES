#include<bits/stdc++.h>
using namespace std;
using ll = long long; // %lld
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rall(a) (a).rbegin(), (a).rend()
const ll INF = 1e9;

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
    sort(rall(A));
    ll ans = INF;
    FOR(i,0,(1 << n)) {
        ll diff = 0;
        FOR(j,0,n) {
            (i & (1 << j)) ? diff += A[j] : diff -= A[j];
        }
        if(diff >= 0) ans = min(ans,diff);
    }
    cout << ans << endl;
    return 0;
}