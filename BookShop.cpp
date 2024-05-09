#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
const int INF = 1e9;
int n, x;
vi h, s;
vector<vi> dp;

/* Recursive Version. f(0,0)
int f(int i, int c) {
    if(c >  x) return -INF;
    if(i == n) return 0;
    return max(f(i+1,c), s[i]+f(i+1,c+h[i]));
} */

void f() {
    FOR(i,1,n+1) FOR(j,0,x+1) {
        dp[i][j] = dp[i-1][j];
        int k = j-h[i-1]; 
        if(k >= 0) { // Money Available
            dp[i][j] = max(dp[i][j], dp[i-1][k]+s[i-1]);
        }
    }
    cout << dp[n][x] << endl;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    h.resize(n), s.resize(n); dp.assign(n+1,vi(x+1,0));
    FOR(i,0,n) cin >> h[i];
    FOR(i,0,n) cin >> s[i];
    f();
    return 0;
}