#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)

int main() {
    int n; cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    int a = n-1, b = n;
    while(a >= 1) {
        cout << a << " ";
        a-=2;
    }
    while(b >= 1) {
        cout << b << " ";
        b-=2;
    }
    cout << endl;
    return 0;
}