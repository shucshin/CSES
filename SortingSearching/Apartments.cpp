#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

int main() {
    int n, m, k; cin >> n >> m >> k;
    vi applicants(n), apartments(m);
    rep(i,0,n) cin >> applicants[i];
    rep(i,0,m) cin >> apartments[i];
    sort(all(applicants)); sort(all(apartments));
    int a=0, b=0, ans=0;
    while(a < n && b < m) {
        if(abs(applicants[a]-apartments[b]) <= k) {
            a++; b++; ans++;
        }
        else if(abs(applicants[a]-apartments[b]) > k) {
            if(applicants[a] < apartments[b]) a++;
            else b++;
        }
    }
    cout << ans << endl;
    return 0;
}