#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, sum = 0; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i]; sort(all(A));
    for(auto a : A) {
        if(sum+1 < a) {
            cout << sum+1 << endl;
            return 0;
        }
        sum += a;
    }   cout << sum+1 << endl;

    return 0;
}