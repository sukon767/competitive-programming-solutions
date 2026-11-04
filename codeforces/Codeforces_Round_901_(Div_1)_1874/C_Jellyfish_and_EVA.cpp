#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
    }

    vector<vector<ld>> dp(n+1);
    for(int i = 1; i <= n; i+=2) {
        dp[i] = vector<ld>(i);
        for(auto& x : dp[i]) x = (ld)1/i;
    }
    dp[2] = {0, 0.5};
    for(int i = 4; i <= n; i+=2) {
        dp[i] = vector<ld>(i); dp[i].back() = 1;
        for(int j = 0; j < i-1; j++) {
            if(j < i-2) dp[i][j] += (i-2-j)*dp[i-2][j];
            if(j) dp[i][j] += j*dp[i-2][j-1];
        }
        for(auto& x : dp[i]) x/=i;
    }


    // for(int i = 0; i <= n; i++) {
    //     cout << i << endl;
    //     for(auto& x : dp[i]) cout << x << " ";
    //     cout << endl;
    // }

    vector<ld> dp2(n); dp2.back() = 1;
    for(int i = n-2; i >= 0; i--) {
        if(!sz(adj[i])) continue;
        vector<ld> cont;
        for(int y : adj[i]) cont.push_back(dp2[y]);
        sort(all(cont));
        for(int j = 0; j < sz(cont); j++) {
            dp2[i] += dp[sz(cont)][j]*cont[j];
        }
        // cout << i << " " << dp2[i] << endl;
    }

    cout << setprecision(20) << dp2[0];
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