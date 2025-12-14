#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define  FOR(i,a,b) for(int i = (a); i < (b); i++)

vi Z(string s, string t) {
    string a = t+"$"+s; int n = a.length(), m = t.length();
    vi p(n), z;
    for(int i=1, l=0, r=0; i < n; ++i) {
        if(i <= r) p[i] = min(r-i+1ll, p[i-l]);
        while(i+p[i] < n && a[p[i]] == a[i+p[i]]) ++p[i];
        if(i+p[i]-1 > r) l=i, r=i+p[i]-1;
    }
    FOR(i,0,n) {if(p[i] == m) z.pb(i-m-1);}
    return z;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    cout << Z(s,t).size() << endl;
    return 0;
}