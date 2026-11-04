#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<ll>> p(n, vector<ll>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> p[i][j];

    // cout << "asdf\n";

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m+1, vector<ll>(k+1, -1)));
    if(c[0])
        dp[0][c[0]][1] = 0;
    else
        for(int i = 1; i <= m; i++)
            dp[0][i][1] = p[0][i-1];
        
    // cout << "asdf\n";

    for(int i = 1; i < n; i++)
        for(int j = 1; j <= k; j++) {
            // cout << "asdf\n";

            multiset<ll>    miner;
            for(int j2 = 1; j2 <= m; j2++)
                if(dp[i-1][j2][j-1] != -1)
                    miner.insert(dp[i-1][j2][j-1]);

            

            if(c[i]) {

                ll temp = dp[i-1][c[i]][j-1];

                auto it = miner.find(temp);
                if(it != miner.end())
                    miner.erase(it);

                if(dp[i-1][c[i]][j] != -1)
                    miner.insert(dp[i-1][c[i]][j]);

                if(miner.size())
                    dp[i][c[i]][j] = *miner.begin();

            } else
                for(int j2 = 1; j2 <= m; j2++) {

                    ll temp = dp[i-1][j2][j-1];

                    auto it = miner.find(temp);
                    if(it != miner.end())
                        miner.erase(it);

                    if(dp[i-1][j2][j] != -1)
                        miner.insert(dp[i-1][j2][j]);

                    //meat
                    if(miner.size())
                        dp[i][j2][j] = *miner.begin() + p[i][j2-1];
// cout << "asdf\n";
                    if(dp[i-1][j2][j] != -1) {
                        auto it2 = miner.find(dp[i-1][j2][j]);
                        miner.erase(it2);
                    }
                        
                    if(temp != -1)
                        miner.insert(temp);
                        // cout << "asdf\n";
                }
            // for(int j2 = 1; j2 <= m; j2++)
            //     cout << i << " " << j2 << " " << j << " " << dp[i][j2][j] << "\n";
        }

    // cout << "asdf\n";

    ll ans = 1e18;
    for(int j2 = 1; j2 <= m; j2++)  
        if(dp[n-1][j2][k] != -1)
            ans = min(ans, dp[n-1][j2][k]);

    if(ans == 1e18) cout << -1;
    else cout << ans;

    return 0;
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}