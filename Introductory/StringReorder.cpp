#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll n = s.size();
    vi cnt(26, 0);
    FOR(i,0,n) cnt[s[i] - 'A']++;
 
    ll mx = 0; FOR(i,0,26) mx = max(mx, cnt[i]);
 
    if (mx > (n + 1) / 2) { cout << -1 << endl; return 0; }
    string ans; ans.reserve(n);
    char last = '#';
    FOR(pos,0,n) {
        bool placed = false;
        FOR(c,0,26) {
            if (cnt[c] == 0) continue;
            char ch = char('A' + c);
            if (ch == last) continue;
            cnt[c]--;
            ll rem = n - pos - 1;
            ll mxr = 0; FOR(k,0,26) mxr = max(mxr, cnt[k]);
            if (mxr <= (rem + 1) / 2) {
                ans.pb(ch);
                last = ch;
                placed = true;
                break;
            }
            cnt[c]++;
        }
        if (!placed) { cout << -1 << endl; return 0; }
    }
    cout << ans << endl;
    return 0;
}