#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    int mx = 0;
    vector<pair<int, int>> dp(n, {-1, 1});
    for(int i = n-1; i >= 0; i--) {
        // cout << i << endl;
        if(i + a[i]+1 == n) dp[i].f = 1;
        else if(i+a[i]+1 < n && dp[i+a[i]+1].f != -1) dp[i].f = dp[i+a[i]+1].f+1;
        dp[i].s = mx + 1;
        if(i+a[i]+1 < n) dp[i].s = max(dp[i].s, dp[i+a[i]+1].s+1); 
        mx = max(mx, dp[i].f);

        // cout << i << " " << dp[i].f << " " << dp[i].s << endl;
    }

    for(int i = 0; i < n-1; i++) {
        if(a[i] == dp[i+1].f) cout << 0;
        else if(dp[i+1].f != -1) cout << 1;
        else if(dp[i+1].s >= a[i]) cout << 1;
        else cout << 2;
        cout << " ";
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */