#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string s; cin >> s;
    vector<int> suf(s.size());
    for(int i = 0; i < s.size(); i++) if(s[i] == '7') suf[i]++;
    for(int i = int(s.size())-2; i >= 0; i--) suf[i] += suf[i+1];
    ll ans = 0;
    for(int i = 0; i < s.size(); i++) if(s[i] == '6') ans += suf[i];
    cout << ans;
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