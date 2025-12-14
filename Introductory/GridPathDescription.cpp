#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll ans = 0;
string s;
vector<vi> vis(7,vi(7,0));
 
bool inb(ll x, ll y) {
    return 0 <= x && x < 7 && 0 <= y && y < 7;
}
 
vector<pi> moves = {
    {0,-1}, {0,1}, {-1,0}, {1,0}
    // L      R      U       D
};
 
void dfs(ll r, ll c, ll t) {
    if(r == 6 && c == 0) { if (t == 48) ans++; return; }
    if(t == 48) return;
    vis[r][c] = 1;
 
    bool U = (r == 0) || vis[r-1][c];
    bool D = (r == 6) || vis[r+1][c];
    bool L = (c == 0) || vis[r][c-1];
    bool R = (c == 6) || vis[r][c+1];
    if ((U && D && !L && !R) || (L && R && !U && !D)) { vis[r][c] = 0; return; }
    
    FOR(i,0,4) {
        auto &[x,y] = moves[i];
        ll nx = r + x, ny = c + y;
 
        if(!inb(nx,ny) || vis[nx][ny]) continue;
        if(i == 0 && (s[t] == '?' || s[t] == 'L')) dfs(nx, ny, t + 1);
        if(i == 1 && (s[t] == '?' || s[t] == 'R')) dfs(nx, ny, t + 1);
        if(i == 2 && (s[t] == '?' || s[t] == 'U')) dfs(nx, ny, t + 1);
        if(i == 3 && (s[t] == '?' || s[t] == 'D')) dfs(nx, ny, t + 1);
    }
    vis[r][c] = 0;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}