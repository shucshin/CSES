#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll bcpow(ll a, ll b){ll r = 1; while(b) {if(b&1ll) r = r * a %MOD; a = a * a %MOD; b >>= 1ll;} return r;}

int main() {
    ll n; cin >> n;
    cout << bcpow(2, n) << endl;
    return 0;
}