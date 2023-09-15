#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void towerHanoi(int n, char from, char to, char aux) {
    if(n == 0) return;
    towerHanoi(n-1,from,aux,to);
    cout << from-'@' << " " << to-'@' << endl;
    towerHanoi(n-1,aux,to,from);
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n; cin >> n; cout << pow(2,n)-1 << endl;
    towerHanoi(n,'A','C','B');
    return 0;
}