#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i];
 
    vi L(n,-1), R(n, n); stack<ll> stk;
    FOR(i,0,n) {
        while(!stk.empty() && A[i] < A[stk.top()]) {
            R[stk.top()] = i;
            stk.pop();
        }     stk.push(i);
    }
    RFOR(i,0,n) {
        while(!stk.empty() && A[i] < A[stk.top()]) {
            L[stk.top()] = i;
            stk.pop();
        }     stk.push(i);
    }
 
    ll ans = 0;
    FOR(i,0,n) {
        ll area = (R[i] - L[i] - 1) * A[i];
        ans = max(ans, area);
    }
    cout << ans << endl;
    
    return 0;
}