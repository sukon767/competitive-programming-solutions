#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n); for(int&i : a) cin >> i;
    for(int& i : b) cin >> i;
    vector<int> f1(n+2, n), f2(n+2, n);
    vector<int> dp(n);

    ll ans = 0;
    int one = n;

    for(int i = n-1; i >= 0; i--) {
        if(a[i] != b[i]) {
            dp[i] = 0;
        } else if(f1[a[i]+1] != f2[b[i]+1]) {
            dp[i] = min(f1[a[i]+1], f2[b[i]+1])-i;
        } else {
            dp[i] = f1[a[i]+1]-i;
            if(f1[a[i]+1] < n) dp[i] += dp[f1[a[i]+1]];
        }

        


        if(a[i] == 1 || b[i] == 1) one = i;
        ans += one-i + (one == n ? 0 : dp[one]);

        // cout << i << " " << dp[i] << " " << one-i+dp[i] << endl;

        f1[a[i]] = i;
        f2[b[i]] = i;
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