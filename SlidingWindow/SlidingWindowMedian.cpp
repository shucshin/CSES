#include <bits/stdc++.h>
#include <bits/extc++.h>  // pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using vi = vector<ll>;
 
#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define fo(a) find_by_order(a)
#define ok(a) order_of_key(a)
template<class T> using ost = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // for multiset less<T> -> less_equal<T>
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    ost<ll> tree;
    vi A(n); FOR(i,0,n) cin >> A[i];
 
    FOR(i,0,n) {
        tree.insert(A[i]);
        if(tree.size() > k) {
            tree.erase(tree.fo(tree.ok(A[i-k])));
        }
        if(tree.size() == k) {
            cout << *tree.fo((k-1)/2) << " ";
        }
    }   cout << endl;
    return 0;
}