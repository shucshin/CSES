#include <bits/stdc++.h>
using namespace std;
using ll = long long;   // %lld
using lli = __int128;
 
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
// cout << __int128
ostream& operator << (ostream &os, const __int128 &v) {
    if(v==0) return (os << "0");
    string s; lli num=v;
    if(v<0) os<<'-', num=-num;
    for(;num>0;num/=10) s.pb((char)(num%10)+'0');
    reverse(all(s));
    return (os<<s);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> x(n), y(n); FOR(i,0,n) cin >> x[i] >> y[i];
    sort(all(x)); sort(all(y));
 
    lli sum = 0;
    FOR(i,0,n) {
        ll k = 2 * i - (n-1);
        sum += k * x[i];
        sum += k * y[i];
    }
    cout << sum << endl;
 
    return 0;
}