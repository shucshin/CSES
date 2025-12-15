#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    vi A(n); FOR(i,0,n) cin >> A[i];
 
    multiset<pi> L, R; // L holds ceil(k/2) smallest (by value), R holds the rest
    ll sumL = 0, sumR = 0;
 
    auto desiredLeft = [&]() { return (k + 1) / 2; };
 
    auto rebalance = [&]() {
        while (L.size() > desiredLeft()) {
            auto it = prev(L.end());
            sumL -= it->first; sumR += it->first;
            R.insert(*it);
            L.erase(it);
        }
        while (L.size() < desiredLeft() && !R.empty()) {
            auto it = R.begin();
            sumR -= it->first; sumL += it->first;
            L.insert(*it);
            R.erase(it);
        }
    };
 
    auto insertVal = [&](pi p) {
        if (L.empty() || p <= *prev(L.end())) { sumL += p.first; L.insert(p); }
        else { sumR += p.first; R.insert(p); }
        rebalance();
    };
 
    auto eraseVal = [&](pi p) {
        auto it = L.find(p);
        if (it != L.end()) { sumL -= it->first; L.erase(it); }
        else {
            it = R.find(p);
            if (it != R.end()) { sumR -= it->first; R.erase(it); }
        }
        rebalance();
    };
 
    auto cost = [&](){
        ll med = prev(L.end())->first;
        return med * (ll)L.size() - sumL + sumR - med * (ll)R.size();
    };
 
    FOR(i,0,k) insertVal({A[i], i});
    cout << cost();
    FOR(i,k,n) {
        insertVal({A[i], i});
        eraseVal({A[i - k], (i - k)});
        cout << " " << cost();
    }   cout << endl;
    return 0;
}