#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
 
    // For each multiple 1..n count how many are <= v
    auto f = [&](ll v) {
        ll cnt = 0;
        FOR(i,1,n+1) {
            cnt += min(n, v / i);
            if(i > v) break;
        }
        return cnt;
    };
 
    ll k = (n * n + 1) / 2;
    ll L = 1, R = n * n;
    while(L <= R) {
        ll m = (L + R) >> 1;
         f(m) < k ? L = m+1 : R = m-1;
    }
    cout << L << endl;
    return 0;
}