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
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
    }
    int a, b; cin >> a >> b; a--; b--;

    vector<bool> ans(n, 1);

    vector<bool> vis(n);
    auto dfs = [&](auto&& self, int x) -> void { 
        vis[x] = true;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
        }
    };

    dfs(dfs, a);
    for(int i = 0; i < n; i++) ans[i]=ans[i]&vis[i];
    fill(all(vis), 0);
    dfs(dfs, b);
    for(int i = 0; i < n; i++) ans[i]=ans[i]&vis[i];

    for(int i = 0; i < n; i++) {
        if(ans[i]) {cout << "yes\n" << i+1; return;}
    }
    cout << "no";
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