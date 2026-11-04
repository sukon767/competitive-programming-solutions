#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    int m = 1e9+7;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1)));
    dp[0][0][0]++;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++) {
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k])%m;
                if(a[i] >= j) dp[i+1][a[i]][k]= (dp[i+1][a[i]][k] + dp[i][j][k])%m;
                else if(a[i] >= k) dp[i+1][j][a[i]]=(dp[i+1][j][a[i]] + dp[i][j][k])%m;
            }

    int ans = 0;
    for(int j = 0; j <= n; j++)
        for(int k = 0; k <= n; k++)
            ans = (ans+dp[n][j][k])%m;
    
    cout << ans;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}