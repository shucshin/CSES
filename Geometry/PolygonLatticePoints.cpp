#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> x(n+1), y(n+1);
    FOR(i,0,n) cin >> x[i] >> y[i];
 
    // Close the polygon
    x[n] = x[0];
    y[n] = y[0];
 
    ll b = 0;  // boundary points
    FOR(i,0,n) {
        ll dx = llabs(x[i+1] - x[i]);
        ll dy = llabs(y[i+1] - y[i]);
        b += gcd(dx, dy);
    }
 
    ll area = 0;
    FOR(i,0,n) {
        area += x[i] * y[i+1] - x[i+1] * y[i];
    }   if(area < 0) area = -area;
 
    ll pts = (area - b + 2) / 2; // interior pts by Pick's theorem
 
    cout << pts << " " << b << endl;
 
    return 0;
}