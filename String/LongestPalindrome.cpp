#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
 
struct PalindromicTree {
    struct Node {
        map<char,int> next;
        int link, len;
        Node(): link(0), len(0) {}
    };
    vector<Node> st;
    string s;
    int suff;              // index of current longest‐suffix palindrome
    vector<int> suffLen;   // suffLen[i] = longest palindrome ending at i
    int bestLen, bestPos;
    ll totalCount;
 
    PalindromicTree(int maxn = 0) {
        st.reserve(maxn + 3);
        init();
    }
 
    void init(){
        st.clear();
        // node 0: imaginary of length -1
        st.push_back(Node());
        st[0].len = -1; st[0].link = 0;
        // node 1: empty of length 0
        st.push_back(Node());
        st[1].len = 0;  st[1].link = 0;
        suff = 1;
        s.clear();
        suffLen.clear();
        bestLen = 0; bestPos = -1;
        totalCount = 0;
    }
 
    void add(char c){
        int pos = s.size();
        s.push_back(c);
        int cur = suff;
        // 1) find palindrome to extend
        while(true){
            int L = st[cur].len;
            if(pos - L - 1 >= 0 && s[pos - L - 1] == c) break;
            cur = st[cur].link;
        }
        // 2) create node if needed
        if(!st[cur].next.count(c)){
            int nw = st.size();
            st[cur].next[c] = nw;
            st.push_back(Node());
            st[nw].len = st[cur].len + 2;
            // set link
            if(st[nw].len == 1){
                st[nw].link = 1;
            } else {
                int linkcur = st[cur].link;
                while(true){
                    int L2 = st[linkcur].len;
                    if(pos - L2 - 1 >= 0 && s[pos - L2 - 1] == c){
                        st[nw].link = st[linkcur].next[c];
                        break;
                    }
                    linkcur = st[linkcur].link;
                }
            }
        }
        // 3) move suff
        suff = st[cur].next[c];
        // 4) record longest ending here
        suffLen.push_back(st[suff].len);
        // 5) update totals
        totalCount++;
        if(st[suff].len > bestLen){
            bestLen = st[suff].len;
            bestPos  = pos;
        }
    }
 
    // Q1) longest palindromic substring so far
    string getLongest() const {
        if(bestLen <= 0)
            return s.substr(0,1);
        return s.substr(bestPos - bestLen + 1, bestLen);
    }
    // Q2) length of longest palindromic suffix
    int longestSuffixLen() const {
        return st[suff].len;
    }
    // Q3) number of distinct palindromic substrings
    int distinctCount() const {
        return (int)st.size() - 2;
    }
    // Q4) total number of palindromic substrings (with multiplicity)
    ll totalPalCount() const {
        return totalCount;
    }
};
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string S;
    cin >> S;
    int n = S.size();
 
    PalindromicTree pt(n);
    for(char c: S) pt.add(c);
 
    cout << pt.getLongest() << "\n";                    // longest substring
 
    return 0;
}