#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)

int main() {
    int t, a, b; cin >> t;
    while(t--) {
        cin >> a >> b;
        ((a+b)%3==0 && (max(a,b) <= min(a,b)*2)) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}