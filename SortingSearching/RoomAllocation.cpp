#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define snd second
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, l, r, i; cin >> n;
    vector<tuple<ll,ll,ll>> A(n);
    FOR(i,0,n) {
        cin >> l >> r;
        A[i] = {l, r, i};
    }
    // < ascending, > descending
    sort(all(A), [&](auto &a, auto &b) {
        ll l1, r1, i1, l2, r2, i2;
        tie(l1, r1, i1) = a;
        tie(l2, r2, i2) = b;
        return (r1 == r2 ? l1 < l2 : r1 < r2);
    });
    multimap<ll,ll,greater<ll>> mp;
    vi ans(n);
    FOR(x,0,n) {
        tie(l, r, i) = A[x];
        if(mp.upper_bound(l) == mp.end()) {
            ll v = mp.size() + 1;
            ans[i] = v;
            mp.insert({r, v});
            continue;
        }
        auto it = mp.upper_bound(l); // finds first key  < x
        ll v = it->snd;
        ans[i] = v;
        mp.erase(it);
        mp.insert({r,v});
    }
 
    cout << mp.size() << endl;
    for(auto a : ans) cout << a << " "; cout << endl;
 
    return 0;
}