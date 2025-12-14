#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
#define LSOne(a) ((a) & -(a))
#define rep(i,a,b) for(int i = a; i < b; i++)

class Fenwick {
private:
    vll ft;
public:
    Fenwick(int m) {ft.assign(m+1,0);}
    void build(const vll &f) {int m = (int)f.size()-1; ft.assign(m+1,0); for(int i=1; i <= m; ++i) {ft[i] += f[i]; if(i+LSOne(i) <= m) ft[i+LSOne(i)] += ft[i];}}
    Fenwick(const vll &f) {build(f);}
    Fenwick(int m, const vi &s) {vll f(m+1,0); for(int i=0; i < (int)s.size(); ++i) ++f[s[i]]; build(f);}
    ll rsq(int j) {ll sum = 0; for(;j;j-=LSOne(j)) sum += ft[j]; return sum;}
    ll rsq(int i, int j) {return rsq(j) - rsq(i-1);}
    void update(int i, ll v) {for(; i < (int)ft.size(); i+=LSOne(i)) ft[i] += v;}
    int select(ll k) {int l = 1, h = ft.size()-1; for(int i=0; i < 30; ++i) {int m = (l+h)/2; (rsq(1,m) < k) ? l=m : h=m;} return h;}
};

class RUPQ {
private:
    Fenwick ft;
public:
    RUPQ(int m) : ft(Fenwick(m)) {}
    void range_update(int ui, int uj, int v) {ft.update(ui, v); ft.update(uj+1, -v);}
    ll point_query(int i) {return ft.rsq(i);}
};

int main() {
    int n, q, a, b, k; cin >> n >> q;
    vll v(n); rep(i,0,n) cin >> v[i];
    RUPQ ft(n);
    rep(i,1,n+1) {
        ft.range_update(i,i,v[i-1]);
    }
    
    rep(i,0,q) {
        cin >> k;
        if(k == 1) {
            cin >> a >> b >> k;
            ft.range_update(a,b,k);
        } else {
            cin >> k;
            cout << ft.point_query(k) << endl;
        }
    }

    return 0;
}