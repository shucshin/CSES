#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
 
bool isPrime(ll n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (ll i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }   return 1;
}
 
ll next_prime(ll n) {
    if(n < 2) return 2;
    ll x = n + 1;
    if((x & 1) == 0) x++;
    while(!isPrime(x)) x += 2;
    return x;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << next_prime(n) << endl;
    }
    return 0;
}