#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, y; cin >> n;
    vector<tuple<ll,ll,ll>> A;
 
    FOR(i,0,n) {
        cin >> x >> y;
        A.pb({x,y,i});
    }
 
    vi contains(n, 0), contained_by(n, 0);
 
    {   /* If l is descending, we know that all prev l's are in interval,
           so we maintain the min r of prev and if cur r is >= than mn_r, 
           then there cur range contains another range. */
        auto v = A;
        // Custom sort, l desc, r asc
        sort(all(v), [&](auto &a, auto &b) {
            ll l1, r1, i1, l2, r2, i2;
            tie(l1, r1, i1) = a;
            tie(l2, r2, i2) = b;
            return (l1 != l2 ? l1 > l2 : r1 < r2);
        });
        ll mn_r = INF; // min r
        for(auto &t : v) {
            ll l, r, i;
            tie(l, r, i) = t;
            if(mn_r <= r) contains[i] = 1;
            mn_r = min(mn_r, r);
        }
 
    }
 
    {   /* If l is ascending, we know that all prev l's contain cur l in interval,
           so we maintain the max r of prev and if cur r is <= than mx_r, 
           then there cur range is contained by another range. */
        auto v = A;
        // Custom sort, l asc, r desc
        sort(all(v), [&](auto &a, auto &b) {
            ll l1, r1, i1, l2, r2, i2;
            tie(l1, r1, i1) = a;
            tie(l2, r2, i2) = b;
            return (l1 != l2 ? l1 < l2 : r1 > r2);
        });
        ll mx_r = -INF; // max r
        for(auto &t : v) {
            ll l, r, i;
            tie(l, r, i) = t;
            if(r <= mx_r) contained_by[i] = 1;
            mx_r = max(mx_r, r);
        }
    }
 
    for(auto x : contains)     cout << x << " "; cout << endl;
    for(auto x : contained_by) cout << x << " "; cout << endl;
 
    return 0;
}