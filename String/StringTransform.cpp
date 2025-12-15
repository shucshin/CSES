#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define RFOR(i,a,b) for(ll i = (b)-1; i >= (a); i--) 

inline ll code(char c){
  // map '#'→0, 'a'→1, … 'z'→26
  return c=='#' ? 0 : (c - 'a' + 1);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string L; cin >> L; // length = n+1
    ll N = L.size(), n = N-1;
 
    // 1) compute frequency of each char in L
    vi freq(27,0);
    for(auto c : L) freq[ code(c) ]++;
 
    // 2) build C[c] = total # of chars < c
    vi C(27,0);
    FOR(c,1,27) {
        C[c] = C[c-1] + freq[c-1];
    }
 
    // 3) build rank array: rank[i] = # occs of L[i] in L[0..i]
    vi occ(27,0), rk(N);
    FOR(i,0,N) {
        ll ci = code(L[i]);
        occ[ci]++;
        rk[i] = occ[ci];
    }
 
    // 4) find the row where L[row]=='#' (that corresponds to SA entry = 0)
    ll pos = -1;
    FOR(i,0,N) {
        if(L[i]=='#') { pos = i; break; }
    }
    // pos should be >=0
    if(pos < 0) { cout << -1 << endl; return 0; }
 
    // 5) invert BWT: for i=n-1..0, pos = LF(pos);  output L[pos]
    string S(n,'?');
    RFOR(i,0,n) {
        ll c = code(L[pos]);
        pos = C[c] + rk[pos] - 1;
        S[i] = L[pos];
    }
 
    cout << S << endl;
    return 0;
}