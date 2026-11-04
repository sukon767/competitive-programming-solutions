#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    ll t, h, u; cin >> t >> h >> u;
    ll ans = 0;
    ll g1 = min(t, u);
    ans += 4*g1, t -= g1, u -= g1;
    ll g2 = min(t/2, h);
    ans += 7*g2, t -= 2*g2, h -= g2;

    if(t && h) {ans += 5, t--; h--;}
    if(t) {ans += 2*t+1; t = 0;}
    ans += 3*(t+h+u);
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