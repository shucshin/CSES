#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
const ll MOD = 1e9+7;

pi fibs(ll n) {
    if(n == 0) return {0, 1};
    auto p = fibs(n >> 1);
    ll c = (p.fst * (2*p.snd-p.fst))%MOD;
    ll d = (p.fst*p.fst + p.snd*p.snd)%MOD;
    if(c < 0) c += MOD;
    if(d < 0) d += MOD;
    if(n & 1) return {d, c+d};
    else return {c, d};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << fibs(n).fst << endl;
    return 0;
}