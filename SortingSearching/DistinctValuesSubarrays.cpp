#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
    set<ll> S;
    
    ll j = 0, ans = 0;
    FOR(i,0,n) {
        ll k = A[i];
        if(S.count(k)) {
            while(A[j] != k) {
                S.erase(A[j]);
                j++;
            }   S.erase(A[j]); j++;
        }  
        S.insert(k);
        ans += (i - j + 1);
    }
    cout << ans << endl;
 
    return 0;
}