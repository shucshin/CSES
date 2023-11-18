// Disjoint Set Union
#include <bits/stdc++.h>
using namespace std;
using lli = __int128;
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
const ll MOD = 1e9+7;
const ll INF = 1e9;


class DSU {
private:
    vi p, rank, sz;
    ll numSets, largest;
public:
    DSU(int n) {
        p.assign(n,0);
        FOR(i,0,n) p[i] = i;
        rank.assign(n,0);
        sz.assign(n,1);
        numSets = n;
        largest = 1ll;
    }
    int find(int i) {return (p[i]==i) ? i : (p[i] = find(p[i]));}
    bool same(int i, int j) {return find(i) == find(j);}
    ll numDisjoint() {return numSets;}
    ll largestComponent() {return largest;}
    ll size(int i) {return sz[find(i)];}
    void unite(int i, int j) {
        if(same(i,j)) return;
        int x = find(i), y = find(j);
        if(rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        sz[y] += sz[x];
        largest = max(largest,sz[y]);
        --numSets;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v; cin >> n >> m;
    DSU dsu(n);
    FOR(_,0,m) {
        cin >> u >> v; --u, --v;
        dsu.unite(u,v);
        cout << dsu.numDisjoint() << " " << dsu.largestComponent() << endl;
    }
    return 0;
}