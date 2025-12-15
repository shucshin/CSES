#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
 
// Return the starting index k in [0..n) of the lexicographically
// minimal rotation of S, in O(|S|) time.
int booth(const string &S) {
    int n = S.size();
    // We treat T = S + S implicitly via modulo arithmetic
    vector<int> f(2*n, -1);
    int k = 0;  // current candidate start
    for(int j = 1; j < 2*n; ++j) {
        int i = f[j - k - 1];
        while(i != -1 && S[(j % n)] != S[(k + i + 1) % n]) {
            if (S[(j % n)] < S[(k + i + 1) % n])
                k = j - i - 1;
            i = f[i];
        }
        if (i == -1 && S[(j % n)] != S[(k + i + 1) % n]) {
            if (S[(j % n)] < S[(k + i + 1) % n])
                k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
        // once k ≥ n, we can reduce modulo n
        if (k >= n) k %= n;
    }
    return k;
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S; cin >> S;
    int k = booth(S);
    // Output the minimal rotation: S[k..n-1] + S[0..k-1]
    cout << S.substr(k) << S.substr(0,k) << "\n";
    
    return 0;
}