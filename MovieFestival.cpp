#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e18;

bool cmp(pi a, pi b) {return a.snd < b.snd;} 

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, b; cin >> n;
    vector<pi> A(n);
    FOR(i,0,n) {
        cin >> a >> b;
        A[i] = {a,b};
    }   sort(all(A),cmp);

    ll ans = 0, p = 0;
    FOR(i,0,n) {
        if(A[i].fst >= p) {
            ans++;
            p = A[i].snd;
        }
    }
    cout << ans << endl;

    return 0;
}