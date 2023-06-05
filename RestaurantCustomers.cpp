#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using vi = vector<int>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ub(v,a) upper_bound(v.begin(),v.end(),a)-v.begin()-1

int main() {
    int n, a, b; cin >> n;
    priority_queue<int, vi, greater<int> > arrive, leave;
    rep(i,0,n) {
        cin >> a >> b;
        arrive.push(a);
        leave.push(b);
    }
    int ans = 0, c = 0;

    while(!arrive.empty()) {
        if(arrive.top() < leave.top()) {
            arrive.pop(); c++;
            ans = max(ans, c);
        } else {leave.pop(); c--;}
    }
    cout << ans << endl;
    return 0;
}