#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define pb push_back
#define fst first
#define snd second
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

    int i = 0, j = n-1;
    pi p = {-1,-1};
    while(i < j) {
        ll sum = A[i] + A[j];
        if(sum == x) {
            p.fst = m[A[i]][0];
            p.snd = m[A[j]][A[i] == A[j]];
            break;
        }   
        sum < x ? i++ : j--;
    }
    if(p.fst == -1) cout << "IMPOSSIBLE\n";
    else cout << p.fst << " " << p.snd << endl;
    
    return 0;
}