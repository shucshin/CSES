#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
 
struct SuffixAutomaton { // Only handles substrings
    struct State {
        int len, link, first_pos;
        map<char,int> next;
    };
    vector<State> st;
    int last;
    vector<ll> occ;      // endpos‐counts
    vector<int> order;   // topo‐order by len
    vector<ll> cntMul;   // # substrings with multiplicity from each state
 
    SuffixAutomaton(int maxlen = 0) {
        st.reserve(2*maxlen);
        st.push_back({0, -1, -1, {}});
        last = 0;
        occ.pb(0);
    }
 
    //  Extend automaton by character c at original-string index pos
    void extend(char c, int pos) {
        int cur = st.size();
        st.push_back({st[last].len+1, 0, pos, {}});
        occ.push_back(1);
        int p = last;
        while (p>=0 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p < 0) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.push_back(st[q]);      // copy q
                occ.push_back(0);         // clone has no new endpos
                st[clone].len = st[p].len + 1;
                while (p>=0 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
 
    // Must call once after all extend(...) to finalize occ[] and order[]
    void prepare() {
        int N = st.size(), M = 0;
        for (auto &s : st) M = max(M, s.len);
        vector<int> cnt(M+1, 0);
        for (auto &s : st) cnt[s.len]++;
        for (int i = 1; i <= M; i++) cnt[i] += cnt[i-1];
        order.assign(N, 0);
        for (int v = N-1; v >= 0; v--)
            order[--cnt[ st[v].len ]] = v;
        // accumulate occ down link‐tree
        for (int i = N-1; i > 0; i--) {
            int v = order[i], p = st[v].link;
            if (p >= 0) occ[p] += occ[v];
        }
    }
 
    // k-th lexicographic substring (1-based)
    // All distinct substrings in lex order; returns the k-th or "" if none
    string kthSubstring(ll K) const {
        int N = st.size();
        static vector<ll> dp;
        dp.assign(N, -1);
        function<ll(int)> dfs = [&](int v){
            if (dp[v] != -1) return dp[v];
            ll cnt = 0;
            for (auto &p : st[v].next) {
                int u = p.second;
                cnt += 1 + dfs(u);
            }
            return dp[v] = cnt;
        };
        dfs(0);
 
        string ans;
        int v = 0;
        while (K > 0) {
            for (auto &p : st[v].next) {
                char c = p.first;
                int u   = p.second;
                ll cnt  = 1 + dp[u];
                if (K <= cnt) {
                    ans.push_back(c);
                    K--;
                    if (K == 0) return ans;
                    v = u;
                    break;
                }
                K -= cnt;
            }
        }
        return ans;
    }
 
    
};
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    string S; ll K;
    cin >> S >> K;
 
    // Pre-Computation
    SuffixAutomaton sam(S.size());
    FOR(i,0,S.size()) sam.extend(S[i], i);
    sam.prepare();
 
    // k-th lexicographic substring (1-based) no duplicates
    cout << sam.kthSubstring(K) << "\n";
    
    return 0;
}