#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a)   cin >> i;
    vector<pair<int, int>> dp(n+1, {n+1, -1});
    for(int i = 0; i < n; i++) {
        if(dp[a[i]].first == n+1) dp[a[i]] = {i, i};
        else    dp[a[i]].second = i;
    }

    for(int i = 2; i <= n; i++) {
        dp[i].first = min(dp[i].first, dp[i-1].first);
        dp[i].second = max(dp[i].second, dp[i-1].second);
    }

    // for(int i = 1; i <= n; i++) cout << dp[i].first << " " << dp[i].second << "\n";
    if(dp[n].second == -1)  {cout << n; return;}

    int l = 0; int r = n-1;
    for(int i = 1; i <= n; i++) {
        if(dp[i].second == -1)  continue;
        int len = dp[i].second - dp[i].first + 1;
        if(i-len < 0)   {cout << 0; return;}
        l = max(l, dp[i].first-(i-len));
        // cout << dp[i].first-(i-len) << "\n";
        r = min(r, dp[i].second + (i-len));
    }

    cout << r-l+1;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}