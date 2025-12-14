#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'

const int MAXN = 2e5+5;
vll A(MAXN), st(MAXN*4);

int l(int p) {return p << 1;}
int r(int p) {return(p << 1)+1;}
ll conquer(ll a, ll b) {
    if(a==0) return b;
    if(b==0) return a;
    return max(a,b);
}

void build(int p, int L, int R) {
    if(L==R) st[p] = A[L];
    else {
        int m = (L+R)/2;
        build(l(p), L, m);
        build(r(p),m+1,R);
        st[p] = conquer(st[l(p)],st[r(p)]);
    }
}

void update(int p, int L, int R, ll val) {
    if(L==R) {st[p] -= val; cout << L << " ";}
    else {
        int m = (L+R)/2;
        if(st[l(p)] >= val) update(l(p), L, m, val);
        else update(r(p), m+1, R, val);
        st[p] = conquer(st[l(p)], st[r(p)]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m;
    rep(i,1,n+1) cin >> A[i];
    build(1,1,n);
    while(m--) {
        cin >> k;
        if(st[1] < k) cout << "0 ";
        else update(1,1,n,k);
    } cout << endl;
    return 0;
}