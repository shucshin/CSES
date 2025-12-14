#include <bits/stdc++.h>
using namespace std;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
const ll MOD = 1e9+7;
const ll INF = 1e9;
 
class Fenwick {
public:
    ll n; vector<vi> ft;
    Fenwick(ll sz) : n(sz), ft(n+1,vi(n+1,0)) {}
 
    void update(ll x, ll y, ll val) {
        for(        ; x <= n; x += (x & (-x)))
        for(ll i = y; i <= n; i += (i & (-i)))
            ft[x][i] += val;
    }
 
    ll sum(ll x, ll y) {
        ll r = 0;
        for(int i = x; i; i -= (i & (-i)))
        for(int j = y; j; j -= (j & (-j)))
            r += ft[i][j];
        return r;
    }
 
    ll query(ll x1, ll y1, ll x2, ll y2) {
        return sum(x2,y2) - sum(x2,y1-1) - sum(x1-1,y2) + sum(x1-1,y1-1);
    }
};
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q, k; cin >> n >> q;
    Fenwick bit(n);
    FOR(i,1,n+1) FOR(j,1,n+1) {
        char c; cin >> c;
        if(c == '*') bit.update(j,i,1);
    }
 
    FOR(_,0,q) {
        cin >> k;
        if(k == 1) {
            ll x, y; cin >> y >> x;
            if(bit.query(x,y,x,y)) bit.update(x,y,-1);
            else                   bit.update(x,y, 1);
        } else {
            ll x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
            cout << bit.query(x1, y1, x2, y2) << endl;
        }
    }
 
    return 0;
}