#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll MXN = 1e6+5;
const ll MOD = 1e9+7;

ll t, n, dpA[MXN], dpB[MXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    dpA[0] = 1, dpB[0] = 1;
    dpA[1] = 1, dpB[1] = 1;
    FOR(i,2,MXN) {
        dpA[i] = (dpB[i-1]+2*dpA[i-1]) % MOD;
        dpB[i] = (dpA[i-1]+4*dpB[i-1]) % MOD;
    }

    cin >> t;
    while(t--) {
        cin >> n;
        cout << (dpA[n]+dpB[n])%MOD << endl;
    }
    return 0;
}