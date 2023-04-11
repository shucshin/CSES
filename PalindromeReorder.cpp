#include <iostream>
#include <unordered_map>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)

string palindrome(string s) {
    unordered_map<char,int> m; 
    rep(i,0,s.length()) m[s[i]]++; 
    int odd=0; char c; 
    for(auto a : m) {
        if(a.second%2!=0) {
            odd++; c=a.first;
        }
    } 
    if(odd>1 || odd&&s.length()%2==0) return "NO SOLUTION"; 
    string x="", y=""; 
    for(auto a : m) {
        string s(a.second/2,a.first); 
        x=x+s; y=s+y;
    } 
    return (odd) ? (x+c+y) : (x+y);
}

int main() {
    string s; cin >> s;
    cout << palindrome(s) << endl;
    return 0;
}