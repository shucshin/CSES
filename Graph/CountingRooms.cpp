//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using pi = pair<int, int>; // mp(a,b);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a; i < b; i++)

const int n = 1001, m = 1001;
vector<pi> graph[n][m];

void bfs(pi s, vector<pi> graph[n][m], vvi &visited) {
    visited[s.first][s.second] = 1;
    queue<pi> q;
    q.push(s);
    while(!q.empty()) {
        pi u = q.front(); q.pop();
        for(auto v : graph[u.first][u.second]) {
            if(!visited[v.first][v.second]) {
                visited[v.first][v.second] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, m; cin >> n >> m; cin.ignore();
    vvi visited(n,vi(m,0));
    string s;
    rep(i,0,n) {
        getline(cin,s);
        rep(j,0,m) {
            if(s[j] == '.') {
                graph[i][j].pb(mp(i,j));
                //left
                if(j-1 >= 0 && s[j-1] == '.') {
                    graph[i][j].pb(mp(i,j-1));
                    graph[i][j-1].pb(mp(i,j));
                }
                //right
                if(j+1 <= n-1 && s[j+1] == '.') {
                    graph[i][j].pb(mp(i,j+1));
                    graph[i][j+1].pb(mp(i,j));
                }
                // up
                if(i-1 >= 0 && !graph[i-1][j].empty()) {
                    graph[i][j].pb(mp(i-1,j));
                    graph[i-1][j].pb(mp(i,j));
                }
            }
        }
    }
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            if(!graph[i][j].empty() && !visited[i][j]) {
                bfs(mp(i,j), graph, visited);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}