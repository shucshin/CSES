#include<bits/stdc++.h>
using namespace std;
using lli = __int128;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()

ll factorial(ll n) {
    if(n == 1) return 1;
    return factorial(n-1)*n;
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string s; cin >> s; sort(all(s));
    map<int,char> m; FOR(i,0,s.length()) {m[s[i]]++;}
    ll d = 1;
    for(auto a : m) {d*=factorial(a.snd);}
    ll n = factorial(s.length())/d;
    cout << n << endl;
    do {
        cout << s << endl;
    } while(next_permutation(all(s)));
    return 0;
}