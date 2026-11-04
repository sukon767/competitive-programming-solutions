#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) if(s[i] == 'Y') cnt++;
    if(cnt <= 1) cout << "YES";
    else cout << "NO";
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}