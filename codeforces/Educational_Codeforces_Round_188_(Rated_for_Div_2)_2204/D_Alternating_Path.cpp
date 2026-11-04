#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<bool> col;
vector<int> visited;
vector<vector<int>> adj;
vector<int> comp;
 
bool dfs(int x) { 
    bool ans = true;
 
    for(int y : adj[x]) {
        if(visited[y] == 2) continue;
 
        if(visited[y] == 1) {
            if(col[y] == col[x]) {ans = false;}
        } else {
            col[y] = !col[x];
            visited[y] = 1;
            comp[y] = comp[x];
            if(!dfs(y)) {ans = false;}
        }
    }
 
    visited[x] = 2;
    return ans;
}
 
void solve() {
    int n, m; cin >> n >> m;
    col = vector<bool>(n);
    visited = vector<int>(n);
    adj = vector<vector<int>>(n);
    comp = vector<int>(n);
 
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; adj[--u].push_back(--v); adj[v].push_back(u);
    }
 
    
    int on = 0;
    vector<bool> work;
 
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        comp[i] = on;
        if(!dfs(i)) work.push_back(false);
        else work.push_back(true);
        on++;
    }
 
 
 
    vector<pair<int, int>> per(on);
    for(int i = 0; i < n; i++) {
        if(!work[comp[i]]) continue;
 
        per[comp[i]].first++;
        if(col[i]) {per[comp[i]].second++;}
    }
 
    int ans = 0;
    for(int i = 0; i < on; i++) ans += max(per[i].second, per[i].first - per[i].second);
 
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