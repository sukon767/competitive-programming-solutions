#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string s; cin >> s;

    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        
        if(s[i] == '(') cur++;
        else cur--;

        // cout << cur << " " << i << " " << s.size() << endl;
        if(cur == 0 && i+1 < s.size()) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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