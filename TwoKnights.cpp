#include <iostream>
#include <vector>
using namespace std;
using ld = long double;
using ll = long long;
#define rep(i,a,b) for(int i = a; i < b; i++)

ll nCk(ll n, ll k) {
    ld r = 1;
    rep(i,1,k+1) r = r * (n-k+i)/i;
    return (ll)(r+0.01);
}

int main() {
    int n; cin >> n;
    ll ans;
    rep(i,1,n+1) {
        ans = nCk(i*i,2);
        if(i > 2) ans -= 4*(i-1)*(i-2);
        cout << ans << endl;
    }
    return 0;
}