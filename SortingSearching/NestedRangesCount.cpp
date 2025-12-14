#include <bits/stdc++.h>
#include <bits/extc++.h>  // pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define ok(a) order_of_key(a)
template<class T> using ost = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct Range { ll l, r, i; };
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<Range> A(n);
    FOR(i,0,n){
        ll l, r; cin >> l >> r;
        A[i] = {l, r, i};
    }
 
    vector<ll> contains(n,0), contained_by(n,0);
    {
        auto v = A;
        // count how many other ranges each i contains
        sort(all(v), [](auto &a, auto &b){
            return (a.l != b.l ? a.l > b.l : a.r < b.r);
        });
        {
            ost<ll> tree;
            for(auto [l,r,i] : v) {
                ll x = tree.ok(r+1);
                tree.insert(r);
                contains[i] = x;
            }
        }
    }
 
    {
        auto v = A;
        // count how many other ranges each i is contained by
        sort(all(v), [](auto &a, auto &b){
            return (a.l != b.l ? a.l < b.l : a.r > b.r);
        });
        {
            ost<ll> tree;
            for(auto [l,r,i] : v) {
                tree.insert(r);
                ll x = tree.ok(r);
                contained_by[i] = tree.size() - (x+1);
            }
        }
    }
 
    for(auto x : contains)     cout << x << " "; cout << endl;
    for(auto x : contained_by) cout << x << " "; cout << endl;
 
    return 0;
}