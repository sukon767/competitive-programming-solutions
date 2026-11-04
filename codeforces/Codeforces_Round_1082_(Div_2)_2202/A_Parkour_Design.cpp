#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int x, y; cin >> x >> y;
    int s = (x+y)/3;
    if(3*s == x+y && -s <= y && y <= s) cout << "YES";
    else cout << "NO";
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