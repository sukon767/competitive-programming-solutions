#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n; cin >> n;
    vector<ll> h(n); for(ll& i : h) cin >> i;
    vector<ll> dp(n);
    ll mx = -1;
    for(ll i = n-2; i >= 0; i--) {
        dp[i] = min(h[i+1], i+1) + (mx==-1 ? n-i-2 : dp[mx]+mx-i-2);
        // cout << i << " " << h[i+1] << " " << mx << " " << dp[i] << endl;
        if(mx==-1) {
            if(dp[i+1]>n-i-2) mx=i+1;
        } else {
            if(dp[i+1]+(i+1)>dp[mx]+mx) mx=i+1;
        }
    }
    ll ans = accumulate(h.begin(), h.end(), 0LL);
    ll mx2 = 0;
    for(int i = 0; i < n; i++) {
        mx2 = max(mx2, dp[i]);
    }
    cout << ans-mx2;
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