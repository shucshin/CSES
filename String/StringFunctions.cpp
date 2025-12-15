#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll n = s.size();
 
    // 1) Z‐array
    vector<ll> z(n);
    z[0] = 0;                  // by definition z(1)=0
    ll l = 0, r = 0;
    FOR(i,1,n) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        else
            z[i] = 0;
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r){ l = i; r = i + z[i] - 1; }
    }
 
    // 2) prefix‐function (π)
    vector<ll> pi(n);
    pi[0] = 0;  // π(1)=0
    FOR(i,1,n) {
        ll j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
 
    // output z(1..n)
    FOR(i,0,n) {
        cout << z[i] << (i+1 < n ? " " : "\n");
    }
    // output π(1..n)
    FOR(i,0,n) {
        cout << pi[i] << (i+1 < n ? " " : "\n");
    }
    return 0;
}