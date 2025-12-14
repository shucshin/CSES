#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, j = 0, ans = 0; cin >> n;
    vi A(n);   FOR(i,0,n) cin >> A[i];
    map<ll,ll> songs;
    FOR(i,0,n) {
        songs[A[i]]++;
        while(songs[A[i]] > 1) {
            songs[A[j]]--;
            j++;
        }
        ans = max(ans,i-j+1);
    }
    cout << ans << endl;
    return 0;
}