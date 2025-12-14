#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
// Print all the process
void josephus2(ll n, ll k) {
    vector<vi> A; vi v;
    ll r = 0, c = 0, cnt = 0, rt = sqrt(n);
 
    FOR(i,1,n+1) { // Make rows of size k+1
        if(cnt > rt) {
            cnt = 0;
            A.pb(v);
            v.clear();
        }
        v.pb(i); cnt++;
    }   if(!v.empty()) A.pb(v);
 
    FOR(i,0,n) {
        ll j = k % (n-i); // pos of del elem
        while(j) {
            // Jump j elems in cur row if possible
            if(c + j < A[r].size()) c += j, j = 0;
            else { // if not, jump to next row
                j -= A[r].size() - c;
                c = 0;
                r++;
            }
            // If all elems are traversed, start from fst row again
            if(r >= A.size()) r = 0;
        }
        // While cur row has lesser cols, move to nxt row
        while(A[r].size() <= c) {
            c = 0; r++;
            if(r >= A.size()) r = 0;
        }   cout << A[r][c] << " ";
 
        if(i != n-1) { // Remove elem of cur row
            A[r].erase(A[r].begin() + c);
            while(A[r].size() <= c) {
                c = 0; r++;
                if(r >= A.size()) r = 0;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    
    josephus2(n, k);
    
    return 0;
}