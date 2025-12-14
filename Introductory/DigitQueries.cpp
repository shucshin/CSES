#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = __int128;
using vi = vector<ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vi p10(20);
 
void calc() {
    p10[0] = 1;
    FOR(i,1,19) p10[i] = p10[i-1] * 10;
}
 
void solve() {
    ll k; cin >> k;
    for(ll d = 1; d <= 18; d++) { // # of digits
        ll cnt = 9 * p10[d-1]; // d-digit nums
        lli block = (lli)cnt * d; // total digits in this block
        if(k > block) { k -= block; continue; } 
        ll c = k / d; // full d-digit numbers
        ll r = k % d; // position of next num
        ll base = p10[d-1];
        if(r == 0) { // last digit of c-th number
            ll num = base + c - 1;
            cout << (num % 10) << endl;
            return;
        } else {
            ll num = base + c;
            ll digit = (num / p10[d - r]) % 10; // get r-th digit
            cout << digit << endl;
            return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    calc();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}