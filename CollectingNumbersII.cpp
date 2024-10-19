#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, a, b, x, res = 1; cin >> n >> m;
    vector<pi> A(n+1);
    map<ll,ll> idx;
    FOR(i,1,n+1) {
        cin >> x;
        A[i] = {x,i};
    }   sort(all(A));
    FOR(i,1,n) if(A[i].snd > A[i+1].snd) res++;
    FOR(i,1,n+1) idx[A[i].snd] = A[i].fst;

    FOR(_,0,m) {
        cin >> a >> b;
        ll x = idx[a], y = idx[b];

        if(abs(x-y) == 1) {
            ll p = min(x,y);
            res -= (A[p-1].snd > A[p].snd) + (A[p].snd > A[p+1].snd) + (A[p+1].snd > A[p+2].snd);
        } else {
            res -= (A[x-1].snd > A[x].snd) + (A[x].snd > A[x+1].snd) + (A[y-1].snd > A[y].snd) + (A[y].snd > A[y+1].snd);
        }

        swap(A[x].snd,A[y].snd); 
        idx[a] = y; 
        idx[b] = x;

        if(abs(x-y) == 1) {
            ll p = min(x,y);
            res += (A[p-1].snd > A[p].snd) + (A[p].snd > A[p+1].snd) + (A[p+1].snd > A[p+2].snd);
        } else {
            res += (A[x-1].snd > A[x].snd) + (A[x].snd > A[x+1].snd) + (A[y-1].snd > A[y].snd) + (A[y].snd > A[y+1].snd);
        }

        cout << res << endl;
    }
    return 0;
}