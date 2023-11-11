#include <bits/stdc++.h>
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
const ll MOD = 1e9+7;
const ll INF = 1e9;

ll bcpow(ll a, ll b, ll m=MOD){
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}

void solve() {
    ll a, b; cin >> a >> b;
    cout << bcpow(a,b) << endl;
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}