#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i = a; i < b; i++)

int main() {
    int n; cin >> n;
    ll a; cin >> a;
    ll b, ans=0;
    rep(i,1,n) {
        cin >> b;
        if(b<a) {ans += (a-b); continue;}
        a = b;
    }
    cout << ans << endl;
    return 0;
}