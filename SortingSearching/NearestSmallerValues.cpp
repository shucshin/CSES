#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vi A(n); for(auto &a : A) cin >> a;
 
    vi L(n,-1);
    stack<ll> stk;
    RFOR(i,0,n) {
        while(!stk.empty() && A[i] < A[stk.top()]) {
            L[stk.top()] = i;
            stk.pop();
        }   stk.push(i);
    }
 
    for(auto x : L) cout << x+1 << " "; cout << endl;
 
    return 0;
}