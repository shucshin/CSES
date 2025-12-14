#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vi A(n); FOR(i,0,n) cin >> A[i];
    map<ll,ll> mp;
    
    ll j = 0, ans = 0;
    FOR(i,0,n) {
        mp[A[i]]++;
        while(mp.size() > k) {
            mp[A[j]]--;
            if(mp[A[j]] == 0) mp.erase(A[j]);
            j++;
        }
        ans += (i - j + 1);
    }
    cout << ans << endl;
 
    return 0;
}