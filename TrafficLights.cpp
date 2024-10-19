#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x, n, a; cin >> x >> n;
    set<ll> S = {0,x};
    multiset<ll> len = {x};
    FOR(_,0,n) {
        cin >> a;
        S.insert(a);
        auto it = S.lower_bound(a);
        ll p = *it;
        it--;
        ll l = *it;
        it++; it++;
        ll r = *it;
        len.erase(len.find(r-l));
        len.insert(r-p);
        len.insert(p-l);
        cout << *--len.end() << " ";
    }   cout << endl;
    return 0;
}