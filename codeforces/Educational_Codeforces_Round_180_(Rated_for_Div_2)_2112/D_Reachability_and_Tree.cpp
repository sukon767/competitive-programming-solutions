#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
        d[u]++; d[v]++;
    }

    int r = -1;
    for(int i = 0; i < n; i++) {
        if(d[i]==2) {r = i; break;}
    }
    if(r == -1) {cout << "NO"; return;}

    vector<bool> vis(n);
    vis[r] = 1;
    vector<pair<int, int>> ans;
    ans.emplace_back(adj[r][0], r);
    ans.emplace_back(r, adj[r][1]);

    auto dfs = [&](auto &&self, int x, bool s) -> void {
        vis[x] = 1;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            if(s) ans.emplace_back(x, y);
            else ans.emplace_back(y, x);
            self(self, y, !s);
        }
    };

    dfs(dfs, adj[r][0], 1); dfs(dfs, adj[r][1], 0);

    cout << "YES\n";
    for(auto&p : ans) cout << p.f+1 << " " << p.s+1 << "\n";
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