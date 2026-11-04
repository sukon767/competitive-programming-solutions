#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll ans = 0;
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(ll& i : a) cin >> i;
    for(ll& i : b) cin >> i;
    ll mx = 0;
    for(int i = 0; i < n; i++) {
        ans += max(a[i], b[i]);
        mx = max(mx, min(a[i], b[i]));
    }

    cout << mx + ans;
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