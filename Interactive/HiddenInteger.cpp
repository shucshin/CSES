#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//==Interactive==
string ask(ll k) {
    cout << "? " << k << endl;
    string r; cin >> r; return r;
}
 
void ans(ll x) {
    cout << "! " << x << endl;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l = 1, r = 1e9;
    while(l <= r) {
        ll m = (l + r) >> 1;
        ask(m) == "YES" ? l = m+1 : r = m-1;
    }
    ans(l);
    return 0;
}