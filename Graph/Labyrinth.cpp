#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e18;
 
ll n, m;
vector<string> AL;
vector<vi> dst;
vector<vector<pi>> par;
 
vector<pi> moves = {
	{0,-1}, {0,1}, {-1,0}, {1,0} // L, R, U, D
};
 
bool inb(ll x, ll y) { 
    return 0 <= x && x < n && 0 <= y && y < m;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	AL.resize(n);
	dst.assign(n,vi(m,INF));
	par.assign(n, vector<pi>(m, {-1, -1}));
 
	FOR(i,0,n) {
		cin >> AL[i];
	}
 
	pi a,b;
 
	FOR(i,0,n) FOR(j,0,m) {
		if (AL[i][j] == 'A') a = {i,j};
		if (AL[i][j] == 'B') b = {i,j};
	}
 
	queue<pi> q;
	dst[a.fst][a.snd] = 0;
	q.push(a);
	while(!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		if (x == b.fst && y == b.snd) break;
		for (auto [dx,dy] : moves) {
			ll nx = x + dx, ny = y + dy;
			if (!inb(nx,ny) || AL[nx][ny] == '#') continue;
			if (dst[nx][ny] != INF) continue;
			dst[nx][ny] = dst[x][y] + 1;
			par[nx][ny] = {x, y};
			q.push({nx,ny});
		}
	}
 
	if(dst[b.fst][b.snd] == INF) {
		cout << "NO" << endl;
		return 0;
	}
 
	cout << "YES" << endl;
	string ans;
	while(a != b) {
		auto [x,y] = b;
		auto [px,py] = par[x][y];
 
		if(x == px && y+1 == py) ans += "L";
		if(x == px && y-1 == py) ans += "R";
		if(x+1 == px && y == py) ans += "U";
		if(x-1 == px && y == py) ans += "D";
		b = {px,py};
	}
 
	reverse(all(ans));
	cout << ans.size() << endl;
	cout << ans << endl;
 
	return 0;
}