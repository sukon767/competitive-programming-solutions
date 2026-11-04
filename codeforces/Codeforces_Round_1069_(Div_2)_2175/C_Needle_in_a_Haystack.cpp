#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string s, ts; cin >> s >> ts;
    map<char, int> cnt;
    for(char x : ts) cnt[x]++;
    // for(auto x : cnt) cout << x.second << endl;
    for(char x : s) {cnt[x]--; if(cnt[x] < 0) {cout << "Impossible"; return;}}
    char c = 'a';
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        while(int(c) < s[i]) {for(int j = 0; j < cnt[c]; j++) ans+=c; c++;}
        ans += s[i];
    }
    // cout << int(c) << endl;
    while(int(c) < int('a') + 26)  {for(int j = 0; j < cnt[c]; j++) ans+=c; c++;}
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