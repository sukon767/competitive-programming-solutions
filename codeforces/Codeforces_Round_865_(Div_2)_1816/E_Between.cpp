#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj = vector<vector<int>>(n);
    vector<vector<int>> val = vector<vector<int>>(1);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--v].push_back(--u);
    }
    queue<pair<int, int>> bfs;
    bfs.push({0, 1});
    vector<bool> vis(n);
    vis[0] = true;
    int ans = 0, cnt = 0;
    while(bfs.size()) {
        auto [x, v] = bfs.front();
        bfs.pop();
        if(v < val.size()) val[v].push_back(x);
        else val.push_back({x});
        ans += v; cnt++;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            vis[y] = true;
            bfs.push({y, v+1});
        }
    }

    if(cnt != n) {cout << "INFINITE"; return;}
    
    cout << "FINITE\n" << ans << "\n";
    for(int i = 1; i < val.size(); i++) {
        for(int j = (int)val.size()-i; j < val.size(); j++) {
            for(int x : val[j]) cout << x+1 << " " ;
        }
    }
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