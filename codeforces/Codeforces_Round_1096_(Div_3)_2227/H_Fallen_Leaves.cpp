#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }    

    vector<pair<ll, ll>> dp(n), res(n);
    vector<bool> vis(n);
    ll ans = LLONG_MAX;
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);   
            dp[x].first += dp[y].first+res[y].first;
            res[x].first += res[y].first;
        }

        if(sz(adj[x]) == 1) res[x].first++;
        res[x].first&=1;
    };

    auto dfs2 = [&](auto&& self, int x) -> void {
        // cout << x+1 << " " << dp[x].first << " " << res[x].first << " " << dp[x].second << " " << res[x].second << endl;

        vis[x] = true;
        //test
        ll resx = 0;
        ll d = 0;
        if(sz(adj[x]) == 1) {
            if(x) d = dp[x].second + res[x].second;
            else d = dp[x].first;
            ans = min(ans, d);
            resx++;
        }

        for(int y : adj[x]) {
            if(vis[y]) continue;
            resx += res[y].first;
        }
        for(int y : adj[x]) {
            if(vis[y]) continue;
            dp[y].second = (dp[x].second+res[x].second) + dp[x].first - (dp[y].first+res[y].first);
            res[y].second = (res[x].second+resx-res[y].first)&1;
            self(self, y);
        }
    };

    dfs(dfs, 0);
    fill(vis.begin(), vis.end(), 0);
    dfs2(dfs2, 0);

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