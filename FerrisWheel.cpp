#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

int main() {
    int n, x; cin >> n >> x;
    vi weights(n);
    rep(i,0,n) cin >> weights[i];
    sort(all(weights));
    int a=0, b=n-1, ans=0;
    while(a <= b) {
        if(weights[a]+weights[b] > x) {b--; ans++;}
        if(weights[a]+weights[b] <= x) {a++; b--; ans++;}
        if(a==b) {ans++; break;}
    }
    cout << ans << endl;
    return 0;
}