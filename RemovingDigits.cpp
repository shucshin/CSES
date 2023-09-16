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

const ll INF = 1e9;

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vi dp(n+1); dp[0] = 0;
    FOR(i,1,n+1) {
        ll tmp = i, steps = INF;
        while(tmp) {
            ll di = tmp%10;
            tmp /= 10;
            if(!di) continue;
            steps = min(steps, 1+dp[i-di]);
        }
        dp[i] = steps;
    }
    cout << dp[n] << endl;
    return 0;
}