#include <bits/stdc++.h>
#include <bits/extc++.h>  // pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define ok(a) order_of_key(a)
template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q, x; cin >> n >> q;
 
    vi A(n+1);
    ost<pi> ms;
 
    FOR(i,1,n+1) {
        cin >> A[i];
        ms.insert({A[i], i});
    }
 
    char c; ll a, b;
    while(q--) {
        cin >> c >> a >> b;
        if(c == '!') {
            ms.erase({A[a], a});
            A[a] = b;
            ms.insert({A[a], a});
        } else {
            ll l = ms.ok(pi(a, -INF));
            ll r = ms.ok(pi(b, INF));
            cout << (r - l) << endl;
        }
    }
    return 0;
}