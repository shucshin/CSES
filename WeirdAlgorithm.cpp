#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    while(n != 1) {
        cout << n << " ";
        n%2==0 ? n/=2 : n=n*3+1;
    }
    cout << 1 << endl;
    return 0;
}