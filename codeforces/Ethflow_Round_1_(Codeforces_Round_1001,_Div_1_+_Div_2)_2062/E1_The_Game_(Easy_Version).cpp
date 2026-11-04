#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void att(pair<int, int>& x, int y) {
    if(y > x.first) x = {y, x.first};
    else if(y > x.second) x.second = y;
};

void solve() {
    int n; cin >> n;
    vector<int> w(n); for(int& i : w) {cin >> i; i--;}
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    set<int> cur;
    vector<int> f(n);
    vector<pair<int, int>> dpdown(n);
    vector<int> dpup(n);
    vector<int> vis(n);

    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            pair<int, int> dy = dpdown[y];
            att(dy, w[y]);
            att(dpdown[x], dy.first);
        }
    };

    auto dfs2 = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            dpup[y] = max(dpup[y], max(max(w[x], dpup[x]), (dpdown[y].first==dpdown[x].first ? dpdown[x].second : dpdown[x].first)));
            self(self, y);
        }
    };

    
    dfs(dfs, 0);
    fill(vis.begin(), vis.end(), 0);
    dfs2(dfs2, 0);
    
    pair<int, int> ans = {-1, 0};
    for(int i = 0; i < n; i++) {
        // cout << i << " " << dpdown[i].first << " " << dpdown[i].second << " " << dpup[i] << endl; 
        if(dpup[i] > w[i]) ans = max(ans, {w[i], i+1});
    }

    cout << ans.second;
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