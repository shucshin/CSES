#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i < b; i++)

int main() {
    ll n, ni, m=0; cin >> n;
    rep(i,1,n+1) m += i;
    rep(i,0,n-1) {cin >> ni; m-=ni;}
    cout << m << endl;
    return 0;
}