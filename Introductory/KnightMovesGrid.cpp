#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
 
ll n;
 
vector<pi> knight_moves = {
    {-2, 1}, {-1, 2}, { 1, 2}, { 2, 1},
    { 2,-1}, { 1,-2}, {-1,-2}, {-2,-1}
};
 
bool inb(ll x, ll y) { 
    return 0 <= x && x < n && 0 <= y && y < n;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
 
    vector<vi> grid(n, vi(n, -1));
    grid[0][0] = 0;
    queue<pi> q; q.emplace(0,0);
    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for(auto [dx,dy] : knight_moves) {
            ll nx = x + dx, ny = y + dy;
            if(!inb(nx, ny) || grid[nx][ny] != -1) continue;
            grid[nx][ny] = grid[x][y] + 1;
            q.emplace(nx,ny);
        }
    }
 
    FOR(i,0,n) {
        FOR(j,0,n) cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}