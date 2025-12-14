#include <iostream>
using namespace std;
using ll = long long;
bool isEven(int n) {return n%2==0;}

void solve() {
    ll y, x; cin >> y >> x;
    ll ans = 0;
    // if y >= x && even, y*y and x times --
    // if y >= x && odd, y--, y*y+1, x times ++
    // if x > y && odd, x*x and y times --
    // if x > y && even, x--, x*x + 1, y times ++
    if(y >= x) {
        x--; isEven(y) ? (ans += y*y-x) : (y--, ans += y*y+x+1);
    } else {
        y--; !isEven(x) ? (ans += x*x-y) : (x--, ans += x*x+y+1);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}