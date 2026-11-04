#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<char> c;
    for(char x: s) c.insert(x);
    if(c.size() == 1){
        cout << "NO\n";
        return;
    }
    if(c.size() == 2){
        cout << "YES\n";
        return;
    }
    if(n >= 4) cout << "YES\n";
    else cout << "NO\n";
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