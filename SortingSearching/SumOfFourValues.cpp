#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    vi A(n); for(auto &a : A) cin >> a;
 
    map<ll,vector<pi>> mp;
    FOR(i,0,n) FOR(j,i+1,n) {
        ll k = A[i] + A[j];
        mp[k].pb({i,j});
    }
 
    FOR(i,0,n) FOR(j,i+1,n) {
        ll k = x - (A[i] + A[j]);
        if(mp.find(k) == mp.end()) continue;
 
        for(auto [a, b] : mp[k]) {
            if(i==a || i==b || j==a || j==b) continue;
            cout << i+1 << " " << j+1 << " " << a+1 << " " << b+1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}