#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MOD = 1e9+7;
 
 
ll sum(ll a, ll b) {
    a += b;
    if(a >= MOD) a -= MOD;
    if(a  < 0)   a += MOD;
    return a;
}
 
ll mul(ll a, ll b) { return a * b % MOD; }
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, ans = 1; cin >> n;
    map<ll,ll> mp;
 
    FOR(_,0,n) {
        cin >> x;
        mp[x]++;
    }
 
    for(auto [k,v] : mp) {
        ans = mul(ans, v+1);
    }
    cout << sum(ans, -1) << endl;
 
    return 0;
}