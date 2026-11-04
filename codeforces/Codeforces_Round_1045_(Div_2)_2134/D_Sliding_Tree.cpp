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
    queue<int> bfs; bfs.push(0);
    vector<bool> vis(n);
    int lst = 0;
    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop();
        vis[x] = true;
        for(int y : adj[x]) {
            if(!vis[y]) bfs.push(y);
        }
        if(!sz(bfs)) lst = x;
    }

    fill(vis.begin(), vis.end(), 0);
    int l2 = 0;
    bfs.push(lst);
    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop();
        vis[x] = true;
        for(int y : adj[x]) {
            if(!vis[y]) bfs.push(y);
        }
        if(!sz(bfs)) l2 = x;
    }
    fill(vis.begin(), vis.end(), 0);
    vector<int> path;
    vector<int> dia;
    
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true; path.push_back(x);
        if(x == l2) {
            dia = path;
        }
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
        }
        path.pop_back();
    };

    dfs(dfs, lst);

    bool ok = false;
    for(int i = 1; i+1 < sz(dia); i++) {
        if(ok) break;
        for(int y : adj[dia[i]]) {
            if(y==dia[i-1] || y==dia[i+1]) continue;
            //slide
            cout << dia[i-1]+1 << " " << dia[i]+1 << " " << y+1;
            ok = true; break;
        }
    }

    if(!ok) cout << -1;
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