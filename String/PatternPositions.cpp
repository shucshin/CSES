#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

struct SuffixAutomaton {
    struct State {
        int len, link, first_pos;
        map<char,int> next;
    };
    vector<State> st;
    int last;
    vector<ll> occ;      // endpos‐counts
    vector<int> order;   // topo‐order by len
 
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
 
    // walk pattern P in the automaton; if found, return
    // the 1‐based start position of its first occurrence, else -1
    int firstOccurrence(const string &P) const {
        int v = 0;
        for(char c: P){
            auto it = st[v].next.find(c);
            if(it == st[v].next.end())
                return -1;
            v = it->second;
        }
        int endpos0 = st[v].first_pos; // 0-based end
        int start0  = endpos0 - (int)P.size() + 1;
        return start0 + 1;             // convert to 1-based
    }
};
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S; cin >> S;
    ll n = S.size();
 
    SuffixAutomaton sa(n);
    FOR(i,0,n) sa.extend(S[i], i);
    sa.prepare();
 
    ll k; cin >> k;
    while(k--) {
        string P; cin >> P;
        cout << sa.firstOccurrence(P) << "\n";
    }
    return 0;
}