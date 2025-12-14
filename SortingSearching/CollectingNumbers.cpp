#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, ans = 1; cin >> n;
    vector<pi> A(n);
    FOR(i,0,n) {
        cin >> A[i].fst; A[i].snd = i;
    }   sort(all(A));
    FOR(i,1,n) {
        if(A[i-1].snd > A[i].snd) ans++;
    }
    cout << ans << endl;
    return 0;
}