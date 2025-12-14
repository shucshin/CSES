#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;

#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

const ll INF = 1e18;
 
ll n, m;
vector<string> AL;
vector<vi> dst, dstM;
vector<vector<pi>> par;
 
vector<pi> moves = {
	{0,-1}, {0,1}, {-1,0}, {1,0} // L, R, U, D
};
 
bool inb(ll x, ll y) { 
    return 0 <= x && x < n && 0 <= y && y < m;
}
 
bool end(ll x, ll y) { 
    return 0 == x || x == n-1 || 0 == y || y == m-1;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	AL.resize(n);
	dst.assign(n,vi(m,INF));
	dstM.assign(n,vi(m,INF));
	par.assign(n, vector<pi>(m, {-1, -1}));
 
	FOR(i,0,n) cin >> AL[i];
 
	pi a;
	vector<pi> monsters;
 
	FOR(i,0,n) FOR(j,0,m) {
		if (AL[i][j] == 'A') a = {i, j};
		if (AL[i][j] == 'M') monsters.emplace_back(i, j);
	}
 
	vector<pi> e; // end
	queue<pi> q;
	dst[a.fst][a.snd] = 0;
	q.push(a);
	if(end(a.fst,a.snd)) e.pb(a);
	while(!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		for (auto [dx,dy] : moves) {
			ll nx = x + dx, ny = y + dy;
			if (!inb(nx,ny) || AL[nx][ny] == '#') continue;
			if (dst[nx][ny] != INF) continue;
			if(end(nx,ny)) e.emplace_back(nx,ny);
			dst[nx][ny] = dst[x][y] + 1;
			par[nx][ny] = {x, y};
			q.push({nx,ny});
		}
	}
 
	queue<pi> q_m;
	for(auto [x,y] : monsters) {
		q_m.emplace(x,y);
		dstM[x][y] = 0;
	}
	while(!q_m.empty()) {
		auto [x,y] = q_m.front(); q_m.pop();
		for (auto [dx,dy] : moves) {
			ll nx = x + dx, ny = y + dy;
			if (!inb(nx,ny) || AL[nx][ny] == '#') continue;
			if (dstM[nx][ny] != INF) continue;
			dstM[nx][ny] = dstM[x][y] + 1;
			q_m.push({nx,ny});
		}
	}
 
	vector<pi> v;
	for(auto [x,y] : e) {
		if(dst[x][y] < dstM[x][y]) {
			v.emplace_back(x,y);
		}
	}
	
	if(v.empty()) {
		cout << "NO" << endl;
		return 0;
	}
 
	cout << "YES" << endl;
	string ans;
	pi b = v[0];
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