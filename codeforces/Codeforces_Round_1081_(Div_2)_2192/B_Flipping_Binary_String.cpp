#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int pop = 0;
    for(int i = 0; i < n; i++) if(s[i] == '1') pop++;
    if(!(pop%2)) {
        cout << pop << "\n";
        for(int i = 0; i < n; i++) if(s[i] == '1') cout << i+1 << ' ';
    } else {
        if(n%2) {cout << "-1"; return;}
        cout << n-pop << "\n";
        for(int i = 0; i < n; i++) if(s[i] == '0') cout << i+1 << ' ';
    }
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