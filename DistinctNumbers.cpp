#include <iostream>
#include <set>
using namespace std;
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < b; i++)

int main() {
    set<int> a;
    int n, x; cin >> n;
    rep(i,0,n) {
        cin >> x;
        a.insert(x);
    }
    cout << a.size() << endl;
    return 0;
}