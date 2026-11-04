#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    ll x, y; cin >> x >> y;
    ll k = y/x;
    if(k > 2) {cout << "YES";}
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */