#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
vector<string> g(8);
 
// Bitmasks for columns and diagonals
// cols: 8 bits for columns used
// d1: main diagonals (r - c + 7) in [0..14]
// d2: anti-diagonals (r + c) in [0..14]
ll dfs(ll r, ll cols, ll d1, ll d2) {
    if (r == 8) return 1;
    ll ways = 0;
    for (ll c = 0; c < 8; ++c) {
        if (g[r][c] == '*') continue;
        ll mc = 1LL << c;
        ll md1 = 1LL << (r - c + 7);
        ll md2 = 1LL << (r + c);
        if ((cols & mc) || (d1 & md1) || (d2 & md2)) continue;
        ways += dfs(r + 1, cols | mc, d1 | md1, d2 | md2);
    }
    return ways;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    FOR(i,0,8) cin >> g[i];
    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}