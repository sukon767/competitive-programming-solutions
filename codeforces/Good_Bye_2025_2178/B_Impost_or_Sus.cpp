#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string s; cin >> s;
    int ans = 0;
    if(s[0] == 'u') ans++;
    if(s[s.size()-1] == 'u') ans++;
    s[0] = 's'; s[s.size()-1] = 's';
    int cur = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 's') {
            if(s[i-1] == 'u') {
                ans += cur/2;
                cur = 0;
            }
        } else cur++;
    }
    cout << ans;
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