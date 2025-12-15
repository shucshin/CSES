#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MOD = 1e9+7;

// fast exponentiation mod
ll modpow(ll a, ll e = MOD-2) {
    ll r = 1;
    while(e) {
        if(e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    string P;
    cin >> n >> P;
    int m = P.size();

    // build π-array for P
    vector<int> pi(m);
    FOR(i,1,m) {
        int j = pi[i-1];
        while(j > 0 && P[i] != P[j]) j = pi[j-1];
        if(P[i] == P[j]) j++;
        pi[i] = j;
    }

    // build KMP-DFA go[state][c]
    vector<array<int,26>> go(m+1);
    FOR(st,0,m+1) {
        FOR(c,0,26) {
            if(st < m && P[st] == 'A'+c)
                go[st][c] = st+1;
            else if(st == 0)
                go[st][c] = 0;
            else
                go[st][c] = go[pi[st-1]][c];
        }
    }

    // dp[i][j] = # length-i strings avoiding P so far, in KMP-state j < m
    vector<ll> dp(m+1), nxt(m+1);
    dp[0] = 1;

    FOR(i,0,n) {
        fill(nxt.begin(), nxt.end(), 0);
        FOR(st,0,m) {
            ll ways = dp[st];
            if(!ways) continue;
            FOR(c,0,26) {
                int nst = go[st][c];
                if(nst < m)
                    nxt[nst] = (nxt[nst] + ways) % MOD;
                // if nst==m we skip: that string would contain P
            }
        }
        dp.swap(nxt);
    }

    // total_avoid = sum of dp[n][j] over j=0..m-1
    ll avoid = 0;
    FOR(j,0,m)
        avoid = (avoid + dp[j]) % MOD;

    // total strings = 26^n
    ll total = modpow(26, n);

    // answer = total - avoid
    ll ans = (total - avoid + MOD) % MOD;
    cout << ans << endl;
    return 0;
}