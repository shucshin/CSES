#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb(a) push_back(a)
const ll MOD = 1e9+7;

int main() {
    ll n; cin >> n;
    ll sum = n*(n+1)/2;
    if(sum%2 != 0) {cout << "NO\n"; return 0;}
    cout << "YES\n"; ll half = sum/2, cur=0, m = n; set<ll> s;
    while(half) {
        if(cur+m >= half) { s.insert(half-cur); break;}
        s.insert(m); cur += m; m--;
    }

    cout << n-s.size() << endl;
    rep(i,1,n+1) {if(s.count(i)) continue; cout << i << " ";} cout << endl;

    cout << s.size() << endl;
    for(auto a : s) cout << a << " "; cout << endl;
    return 0;
}