#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n, k;  cin >> n >> k;
    k = n*(n-1)/2 - k;
    
    vector<vector<vector<int>>>    dp(n+1, vector<vector<int>>(n*(n-1)/2+1));

    for(int i = 1; i <= n; i++) {
        dp[i][i*(i-1)/2] = {i};
    }

    // cout << "asdf\n";

    for(int i = 2; i <= n; i++)
        for(int s = 0; s <= n*(n-1)/2; s++) {
            for(int l = 1; l <= i && l*(l-1)/2 <= s; l++) {
                if(dp[i-l][s - l*(l-1)/2].size()) {
                    dp[i][s] = dp[i-l][s - l*(l-1)/2];
                    dp[i][s].push_back(l);
                }
            }
        }

    // cout << "asdf\n";

    if(!dp[n][k].size()) {
        cout << 0;
        return 0;
    }

    vector<int> ans(n);

    int it = n;
    int i = -1;
    while(i < n-1) {
        // cout << i << " " << dp[n][k][n-it] << "\n";
        i += dp[n][k][n-it];
        ans[i] = it;
        it--;
    }

    int r = 1;
    for(int j = 0; j < n; j++) {
        if(!ans[j]) {
            ans[j] = r;
            r++;
        }
    }

    for(int j = 0; j < n; j++) {
        if(j)   cout << " ";
        cout << ans[j];
    }


    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}