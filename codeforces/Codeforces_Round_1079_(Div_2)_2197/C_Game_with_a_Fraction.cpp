#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll p, q; cin >> p >> q;
    if(p >= q) cout << "Alice";
    else if(3*p >= 2*q) cout << "Bob";
    else cout << "Alice";
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