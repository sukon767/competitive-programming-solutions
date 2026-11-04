#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 1;
    bool t = false;
    for(int i = 1; i < n; i++) if(s[i] != s[i-1]) cnt++; else t = true;
    if(s[0] == s[n-1]) t = false;
    cout << cnt + t;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}