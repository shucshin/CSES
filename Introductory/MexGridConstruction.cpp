#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MXN = 1e4+5;
 
ll used[MXN];
ll grid[105][105];
 
ll mex() {
    ll res = 0;
    while(used[res]) res++;
    return res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    FOR(i,0,n) {
 
        FOR(j,0,n) {
            FOR(k,0,i) used[grid[k][j]]++;
            ll k = mex();
            grid[i][j] = k;
            used[k]++;
            FOR(k,0,i) used[grid[k][j]]--;
        }
 
        FOR(j,0,n) {
            used[grid[i][j]]--;
        }
    }
 
    FOR(i,0,n) {
        FOR(j,0,n) cout << grid[i][j] << " ";
        cout << endl;
    }
 
    return 0;
}