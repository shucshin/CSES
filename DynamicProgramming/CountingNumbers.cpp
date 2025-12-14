#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)

const ll MXN = 20;

ll dp[MXN][2][2]; // index, lower, lead-zero
string a, b;

ll f(string &s, ll i, ll last, ll low, ll lead) {
    if(s[i] == '-')            return 0; // for -1
    if(i == s.size())          return 1;
    if(dp[i][low][lead] != -1) return dp[i][low][lead];
    ll res = 0;
    FOR(x,0,10) {
        if(last == x) { // Repeating digit
            if(!x && lead) res += f(s, i+1, x, 1, 1); // Leading-Zeroes is exception
            continue;
        }
        if(low || x < s[i]-'0') res += f(s, i+1, x, 1, 0);
        else if(x  == s[i]-'0') res += f(s, i+1, x, 0, 0);
    }
    return dp[i][low][lead] = res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    a = to_string(n-1), b = to_string(m);
    memset(dp,-1,sizeof(dp));
    ll x = f(a, 0, 0, 0, 1);
    memset(dp,-1,sizeof(dp));
    ll y = f(b, 0, 0, 0, 1);
    cout << y-x << endl;
    return 0;
}