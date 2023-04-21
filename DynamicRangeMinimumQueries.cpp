#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i,a,b) for(int i = a; i < b; i++)
const int INF = 1e9;

// Segment Tree :: vll a(n), segtree(4*n); v=1, tl=0, tr=n-1;
void build(vll &a, vll &t, int v, int tl, int tr) {
    if(tl==tr) t[v] = a[tl]; 
    else {
        int m = (tl+tr)/2; 
        build(a,t,v*2,tl,m); build(a,t,v*2+1,m+1,tr); 
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

void update(vll &t, int v, int tl, int tr, int pos, ll x) {
    if(tl==tr) t[v]=x; 
    else {
        int m = (tl+tr)/2; 
        (pos<=m) ? update(t,v*2,tl,m,pos,x) : update(t,v*2+1,m+1,tr,pos,x); 
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

ll RMQ(vll &t, int v, int tl, int tr, int l , int r) {
    if(tl>r || tr<l) return INF; 
    if(l<=tl && r>=tr) return t[v]; 
    int m = (tl+tr)/2; 
    return min(RMQ(t,v*2,tl,m,l,r), RMQ(t,v*2+1,m+1,tr,l,r));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, o; cin >> n >> q;
    vll v(n), segtree(n*4);
    rep(i,0,n) cin >> v[i];
    // 2 ^ log_2(n) < 4 * n
    build(v,segtree,1,0,n-1);
    while(q--) {
        cin >> o;
        if(o == 1) {
            int k; ll u; cin >> k >> u; k--;
            update(segtree,1,0,n-1,k,u);
        } else {
            int a, b; cin >> a >> b; a--; b--;
            cout << RMQ(segtree,1,0,n-1,a,b) << "\n";
        }   
    }
}