#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define rep(i,a,b) for(int i = a; i < b; i++)

const int MAXN = 2e5+5;
struct node {ll val, lzAdd, lzSet; node(){};} st[MAXN << 2];

class Segtree {
private:
    int l(int p) {return p << 1;}
    int r(int p) {return(p << 1)+1;}
    void conquer(int p) {st[p].val = st[l(p)].val + st[r(p)].val; return;}

    void propagate(int p, int L, int m, int R) {
        if(st[p].lzSet != 0) {
            st[l(p)].lzSet = st[r(p)].lzSet = st[p].lzSet;
            st[l(p)].val = (m-L+1)*st[p].lzSet;
            st[r(p)].val = (R-m)*st[p].lzSet;
            st[l(p)].lzAdd = st[r(p)].lzAdd = 0;
            st[p].lzSet = 0;
        } else if(st[p].lzAdd != 0) {
            if(st[l(p)].lzSet == 0) st[l(p)].lzAdd += st[p].lzAdd;
            else {
                st[l(p)].lzSet += st[p].lzAdd;
                st[l(p)].lzAdd = 0;
            }
            if(st[r(p)].lzSet == 0) st[r(p)].lzAdd += st[p].lzAdd;
            else {
                st[r(p)].lzSet += st[p].lzAdd;
                st[r(p)].lzAdd = 0;
            }
            st[l(p)].val += (m-L+1)*st[p].lzAdd;
            st[r(p)].val += (R-m)*st[p].lzAdd;
            st[p].lzAdd = 0;
        } return;
    }

    void build(int p, int L, int R) {
        st[p].lzAdd = st[p].lzSet = 0;
        if(L==R) {st[p].val = A[L]; return;}
        int m = (L+R) >> 1;
        build(l(p), L, m);
        build(r(p),m+1,R);
        conquer(p);
        return;
    }

    void add(int p, int L, int R, int i, int j, ll val) {
        if (i > R || j < L) return;
        if (i <= L && R <= j) {
            st[p].val += (R-L+1)*val;
            if(st[p].lzSet == 0) st[p].lzAdd += val;
            else st[p].lzSet += val;
            return;
        }
        int m = (L+R) >> 1;
        propagate(p, L, m, R);
        add(l(p), L, m, i, j, val);
        add(r(p), m+1, R, i, j, val);
        conquer(p);
        return;
    }

    void set(int p, int L, int R, int i, int j, ll val) {
        if (i > R || j < L) return;
        if (i <= L && R <= j) {
            st[p].val = (R-L+1) * val;
            st[p].lzAdd = 0;
            st[p].lzSet = val;
            return;
        }
        int m = (L+R) >> 1;
        propagate(p, L, m, R);
        set(l(p), L, m, i, j, val);
        set(r(p), m+1, R, i, j, val);
        conquer(p);
        return;
    }

    ll query(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return 0;
        if(i <= L && R <= j) return st[p].val;
        int m = (L+R) >> 1;
        propagate(p, L, m, R);
        return query(l(p),L,m,i,j) + query(r(p),m+1,R,i,j);
    }

public:
    int n;
    ll A[MAXN];
    Segtree(int sz) : n(sz) {}
    void build() {build(1,1,n);}
    void add(int i, int j, ll val) {add(1,1,n,i,j,val);}
    void set(int i, int j, ll val) {set(1,1,n,i,j,val);}
    ll query(int i, int j) {return query(1,1,n,i,j);}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, k, a, b; cin >> n >> q;
    ll x;
    Segtree st(n); rep(i,1,n+1) {cin >> st.A[i];} st.build();
    rep(i,0,q) {
        cin >> k;
        if(k == 1) {
            cin >> a >> b >> x;
            st.add(a,b,x);
        } else if(k == 2) {
            cin >> a >> b >> x;
            st.set(a,b,x);
        } else {
            cin >> a >> b;
            cout << st.query(a,b) << endl;
        }
    }
    return 0;
}