#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
// Z-array of a single string a:
vi Z(const string &a) {
    ll n = a.size();
    vi z(n, 0);
    for(ll i = 1, L = 0, R = 0; i < n; i++){
        if(i <= R) z[i] = min(R - i + 1, z[i - L]);
        while(i + z[i] < n && a[z[i]] == a[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > R) { L = i; R = i + z[i] - 1; }
    }
    return z;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll n = s.length();
 
    vi z = Z(s);
    vi ans;
    FOR(x,1,n) {
        if(z[x] >= n - x) ans.pb(x);
    }   ans.pb(n);
 
    for(auto a : ans) cout << a << " "; cout << endl;
 
    return 0;
}