#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> sa(n);
    FOR(i,0,n) {
        cin >> sa[i];
        sa[i]--;                // make 0-based
    }  
 
    // build rank so that rank[pos] = position of suffix pos in SA (1..n),
    // and set rank[n]=0 for the imaginary empty suffix
    vector<ll> rank(n+1);
    FOR(i,0,n) {
        rank[ sa[i] ] = i+1;
    }
    rank[n] = 0;
 
    // answer string
    string s(n, '?');
    s[ sa[0] ] = 'a';
 
    FOR(i,1,n) {
        ll x = sa[i-1], y = sa[i];
        // can we set s[y] = s[x]?  only if suffix at x+1 < suffix at y+1
        bool canEqual = rank[x+1] < rank[y+1];
        char c = s[x];
        if(canEqual) s[y] = c;
        else if(c == 'z') { cout << -1 << endl; return 0; }
        else s[y] = char(c + 1);
    }
 
    cout << s << endl;
    return 0;
}