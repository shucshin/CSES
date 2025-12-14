#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using vi = vector<int>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ub(v,a) upper_bound(v.begin(),v.end(),a)-v.begin()-1

int main() {
    int n, m, a, j; cin >> n >> m;
    multiset<int, greater<int> > tickets;
    rep(i,0,n) {cin >> a; tickets.insert(a);}
    rep(i,0,m) {
        cin >> a;
        j = *tickets.lower_bound(a);
        if(!tickets.count(j)) {cout << -1 << endl; continue;}
        cout << j << endl;
        tickets.erase(tickets.find(j));
    }
    return 0;
}