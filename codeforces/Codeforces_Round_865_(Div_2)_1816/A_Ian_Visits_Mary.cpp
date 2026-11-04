#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int a, b; cin >> a >> b;
    if(a == 1 || b == 1) {
        cout << 1 << "\n";
        cout << a << " " << b;
    } else {
        cout << 2 << "\n";
        cout << 1 << " " << b-1 << "\n";
        cout << a << " " << b;
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */