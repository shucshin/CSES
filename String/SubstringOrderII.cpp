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
    // new: compute cntMul[v] = number of substrings (with multiplicity)
    //      starting from state v, capped at K+1
    void computeMultiplicity(ll K){
        int N = st.size();
        cntMul.assign(N, 0ll);
        // reverse topological over lengths
        for(int idx = N-1; idx >= 0; --idx){
            int v = order[idx];
            ll sum = 0;
            for(auto &ed: st[v].next){
                int u = ed.second;
                // each occurrence of the single char edge
                sum += (ll)occ[u];
                if(sum > K) sum = K+1;
                // plus all longer substrings from u
                sum += cntMul[u];
                if(sum > K) sum = K+1;
            }
            cntMul[v] = sum;
        }
    }
 
    // new: extract the K-th substring in lex order *with multiplicity*
    string kthSubstringWithMultiplicity(ll K){
        string ans;
        int v = 0;
        while(K > 0){
            // scan outgoing edges in 'a'..'z' order
            for(auto &ed: st[v].next){
                char c = ed.first;
                int u   = ed.second;
                // first, all occurrences of the single‐char substring
                ll cnt1 = (ll)occ[u];
                if(K <= cnt1){
                    ans.push_back(c);
                    K = 0;
                    break;
                }
                K -= cnt1;
                // then, all longer substrings prefixed by this edge
                ll cnt2 = cntMul[u];
                if(K <= cnt2){
                    ans.push_back(c);
                    v = u;
                    break;
                }
                K -= cnt2;
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
 
    // build multiplicities
    sam.computeMultiplicity(K); 
 
    // if fewer than K substrings total, no answer
    if(sam.cntMul[0] < K){
        cout << "-1\n";
    } else {
        cout << sam.kthSubstringWithMultiplicity(K) << "\n";
    }
    
    return 0;
}