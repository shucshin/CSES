#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<string> S(n);
    FOR(i,0,n) cin >> S[i];
 
    vector<string> T(n, string(m, 'A'));
    string letters = "ABCD";
    FOR(i,0,n) FOR(j,0,m) {
        for(char c : letters) {
            if(c == S[i][j]) continue;
            if(i > 0 && T[i-1][j] == c) continue;
            if(j > 0 && T[i][j-1] == c) continue;
            T[i][j] = c;
            break;
        }
    }
 
    FOR(i,0,n) cout << T[i] << endl;
    return 0;
}