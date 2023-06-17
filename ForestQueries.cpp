#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; char c;
    vector<vll> forest(n+1,vll(n+1,0));
    rep(i,1,n+1) {
        rep(j,1,n+1) {
            cin >> c;
            forest[i][j] = c == '*';
        }
    }

    vector<vll> pfx(n+1,vll(n+1,0));
    rep(i,1,n+1) {
        rep(j,1,n+1) {
            pfx[i][j] = forest[i][j] + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        }
    }

    int y1, x1, y2, x2;
    rep(i,0,q) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << pfx[y2][x2] - pfx[y1-1][x2] - pfx[y2][x1-1] + pfx[y1-1][x1-1] << endl;
    }

    return 0;
}