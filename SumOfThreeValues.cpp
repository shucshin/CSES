#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    vi A(n);
    map<ll,vi> m;
    FOR(i,0,n) {
        cin >> A[i];
        m[A[i]].pb(i+1); 
    }   sort(all(A));

    vi ans = {-1,-1,-1};
    FOR(i,0,n) {
        int a = 0, b = n-1;
        ll k = x - A[i];
        while(a < b) {
            if(a == i) a++;
            if(b == i) b--;
            if(a >= b) break;
            ll sum = A[a] + A[b];
            if(sum == k) {
                ans[0] = m[A[i]][0];
                ans[1] = m[A[a]][A[i]==A[a]];
                ans[2] = m[A[b]][(A[i]==A[b]) + (A[a]==A[b])];
            }
            sum < k ? a++ : b--;
        }
        if(ans[0] != -1) break;
    }
    if(ans[0] == -1) cout << "IMPOSSIBLE\n";
    else cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    
    return 0;
}