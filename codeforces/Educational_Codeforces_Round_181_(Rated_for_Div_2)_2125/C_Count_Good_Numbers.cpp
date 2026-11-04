#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
void solve() {
    vector<ll> ps = {2, 3, 5, 7};
    ll l, r; cin >> l >> r;
    ll ans = 0;
 
    for(int i = 0; i < (1 << 4); i++) {
        ll d = 1; int c = 0;
        for(int b = 0; b < 4; b++) if(i>>b&1) {d *= ps[b]; c++;}
        if(c&1) ans -= r/d - (l-1)/d;
        else ans += r/d - (l-1)/d;
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
 
 /* new testament
 * nick belov always reads the entire problem statement.
 */
