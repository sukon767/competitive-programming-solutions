#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n), kid(n);
    for(int i = 0; i+1 < n; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<int> f(n+1), dp(n);
    auto dfs = [&](auto&& self, int x, int d) -> void {
        vis[x] = 1; f[d]++; dp[x] = d;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            kid[x].push_back(y);
            self(self, y, d+1);
        }
    };
    dfs(dfs, 0, 0);

    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, f[i]);
    for(int i = 0; i < n; i++) {
        if(sz(kid[i]) == f[dp[i]+1]) ans = max(ans, f[dp[i]+1]+1);
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