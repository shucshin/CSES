#include <iostream>
using namespace std;
using ll = long long;

ll trailing0fac(ll n) {
    ll z = 0; for(ll i = 5; i <= n; i*=5) z += n/i; return z;
}

int main() {
    ll n; cin >> n;
    cout << trailing0fac(n) << endl;
    return 0;
}