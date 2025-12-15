#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

const ll MOD = 1e9+7;

struct Aho {
    struct Node {
        int nxt[26], link;
        vector<int> out;
        Node() { memset(nxt, -1, sizeof(nxt)); link = 0; }
    };
    vector<Node> t;
    Aho() { t.emplace_back(); }
    void insert(const string &w, int id) {
        int v = 0;
        for (char c : w) {
            int x = c - 'a';
            if (t[v].nxt[x] < 0) {
                t[v].nxt[x] = t.size();
                t.emplace_back();
            }
            v = t[v].nxt[x];
        }
        t[v].out.push_back(id);
    }
    void build() {
        queue<int> q;
        for (int c = 0; c < 26; c++) {
            int u = t[0].nxt[c];
            if (u >= 0) q.push(u);
            else     t[0].nxt[c] = 0;
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int f = t[v].link;
            for (int c = 0; c < 26; c++) {
                int &u = t[v].nxt[c];
                if (u >= 0) {
                    t[u].link = t[f].nxt[c];
                    for (int x : t[t[u].link].out)
                        t[u].out.push_back(x);
                    q.push(u);
                } else {
                    u = t[f].nxt[c];
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S; cin >> S;
    ll n = S.size(), k; cin >> k;
    vector<string> dict(k);
    Aho aho;
    FOR(i,0,k) {
        cin >> dict[i];
        aho.insert(dict[i], i);
    }
    aho.build();

    vector<ll> dp(n+1);
    dp[0] = 1;
    int st = 0;
    FOR(i,0,n) {
        st = aho.t[st].nxt[S[i] - 'a'];
        for (int id : aho.t[st].out) {
            int L = dict[id].size();
            int j = i + 1 - L;
            if (j >= 0) dp[i+1] = (dp[i+1] + dp[j]) % MOD;
        }
    }
    cout << dp[n] << endl;

    return 0;
}