#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int x, y, c; cin >> x >> y >> c;
        adj[--x].push_back({--y, c});
        adj[y].push_back({x, c});
    }

    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(5)); //0s, 1s, 01s, 10s, nothing.
    vector<bool> vis(n);

    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        dp[x][4]++;

        for(auto& [y, c] : adj[x]) {
            if(vis[y]) continue;
            self(self, y);

            vector<ll> dpy(5);
            if(c == 1) {
                dpy = {0, dp[y][1]+dp[y][4], dp[y][0]+dp[y][2], 0, 0};
            } else {
                dpy = {dp[y][0]+dp[y][4], 0, 0, dp[y][1]+dp[y][3], 0};
            }

            //upd
            ans += dpy[0]*(2*dp[x][0]+dp[x][1]+dp[x][3]+2*dp[x][4]) + dpy[1]*(dp[x][0]+2*dp[x][1]+dp[x][2]+2*dp[x][4]) + 
            dpy[2]*(dp[x][1]+dp[x][4]) + dpy[3]*(dp[x][0]+dp[x][4]) + dpy[4]*(2*dp[x][0]+2*dp[x][1]+dp[x][2]+dp[x][3]+2*dp[x][4]);

            //add
            for(int i = 0; i < 5; i++) dp[x][i] += dpy[i];
        }

        // cout << x+1 << " " << ans << endl;
        // for(int y : dp[x]) cout << y << " ";
        // cout << endl;
    };

    dfs(dfs, 0);
    
    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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