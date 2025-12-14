#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define fst first
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a; cin >> n;
    vector<pi> A(n); 
    FOR(i,0,n) {
        cin >> a;
        A[i] = {a, i};
    }
 
    vi dp(n,0), L(n,-1), R(n, n); 
    stack<ll> stk;
    FOR(i,0,n) {
        while(!stk.empty() && A[i].fst > A[stk.top()].fst) {
            R[stk.top()] = i;
            stk.pop();
        }   stk.push(i);
    }
    RFOR(i,0,n) {
        while(!stk.empty() && A[i].fst > A[stk.top()].fst) {
            L[stk.top()] = i;
            stk.pop();
        }   stk.push(i);
    }
 
    sort(rall(A));
    for(auto &[x, i] : A) {
        ll l = L[i], r = R[i];
        ll a = (l == -1 ? 0 : dp[l]);
        ll b = (r ==  n ? 0 : dp[r]);
        dp[i] = max(a, b) + 1;
    }
 
    cout << *max_element(all(dp)) << endl;
 
    return 0;
}