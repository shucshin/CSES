#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
// Longest Prefix Suffix
vi LPS(string s) {
    vi A(s.length(),0);
    FOR(i,1,s.length()) {
        int j = A[i-1];
        while(j && s[i] != s[j]) j = A[j-1];
        if(s[i] == s[j]) j++;
        A[i] = j;
    } 
    return A;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll n = s.length();
 
    vi A = LPS(s);
    vi ans;
    for(int x = A[n-1]; x > 0; x = A[x-1]) ans.pb(x);
    reverse(all(ans));
    for(auto a : ans) cout << a << " "; cout << endl;
 
    return 0;
}