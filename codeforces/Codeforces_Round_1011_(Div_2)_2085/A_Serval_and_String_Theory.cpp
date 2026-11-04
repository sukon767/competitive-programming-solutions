#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(!k) {
        string t = s;
        reverse(t.begin(), t.end());
        if(s < t) cout << "YES";
        else cout << "NO";
    } else {
        char c = s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] != c) {cout << "YES"; return;}
        }
        cout << "NO";
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