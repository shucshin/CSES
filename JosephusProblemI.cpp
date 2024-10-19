#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    queue<ll> q;
    FOR(x,1,n+1) q.push(x);
    while(!q.empty()) {
         q.push(q.front());       q.pop();
        cout << q.front() << " "; q.pop();
    }   cout << endl;
    return 0;
}