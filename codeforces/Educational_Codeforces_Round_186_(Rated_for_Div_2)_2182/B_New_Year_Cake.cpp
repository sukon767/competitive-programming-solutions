#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int x, y; cin >> x >> y;
    int a = x, b = y;
    int ans = 0;
    for(int i = 0; i < 100; i++) {
        if(i%2) {
            if(a < (1 << i)) {ans = max(ans, i); break;}
            else a -= (1<<i);
        } else {
            if(b < (1 << i)) {ans = max(ans, i); break;}
            else b -= (1<<i);
        }
    }

    a = x, b = y;
    for(int i = 0; i < 100; i++) {
        if(!(i%2)) {
            if(a < (1 << i)) {ans = max(ans, i); break;}
            else a -= (1<<i);
        } else {
            if(b < (1 << i)) {ans = max(ans, i); break;}
            else b -= (1<<i);
        }
    }

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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */