#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i < b; i++)

string tobinary(ll n, ll bits) {
    string s = ""; 
    for(int i = bits; i >= 0; i--) {
        (1&(n>>i)) ? s+="1" : s+="0";
    } 
    return s;
}

int main() {
    ll n, a, maxn; cin >> n;
    maxn = pow(2,n);
    cout << tobinary(0,n-1) << '\n' << tobinary(1,n-1) << '\n';
    queue<ll> q; q.push(3); q.push(2);
    bool updown = 1;
    while(q.front() < maxn) {
        a = q.front(); q.pop();
        cout << tobinary(a,n-1) << endl;
        updown ? (q.push(a*2),q.push(a*2+1)) : (q.push(a*2+1),q.push(a*2));
        updown ^= 1;
    }
    return 0;
}