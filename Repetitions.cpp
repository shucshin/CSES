#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)

int main() {
    string s; cin >> s;
    int n=0;
    int c=1;
    rep(i,0,s.length()) {
        if(s[i]==s[i+1]) c++;
        else {
            if(n<c) n=c;
            c=1;
        }
    }
    cout << n << endl;
    return 0;
}