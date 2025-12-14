#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;

#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
 
// < ascending, > descending; sort(all(v), cmp); 
bool cmp(pi a, pi b) {return a.snd == b.snd ? a.fst < b.fst : a.snd < b.snd;} 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, l, r; cin >> n >> k;
    vector<pi> A(n);
    FOR(i,0,n) {
        cin >> l >> r;
        A[i] = {l,r};
    }   
    sort(all(A), cmp);
 
    ll ans = n;
    multimap<ll, ll, greater<ll>> mp; // lower_bound finds first key <= x
    FOR(i,0,n) {
        tie(l,r) = A[i];
        if(mp.lower_bound(l) == mp.end()) {
            if(mp.size() < k) mp.insert({r,1});
            else ans--;
            continue;
        }
        auto it = mp.lower_bound(l);
        mp.erase(it);
        mp.insert({r,1});
    }
    cout << ans << endl;
 
    return 0;
}