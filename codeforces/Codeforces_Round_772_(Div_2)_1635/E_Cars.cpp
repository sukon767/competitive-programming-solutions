#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<vector<pair<int, bool>>> adj;
vector<bool> col; vector<int> visited;
bool poss = true;
vector<vector<int>> dag;
vector<int> in;

void dfs(int x) {
    if(!poss) return;
    visited[x] = 2;
    for(auto y : adj[x]) {
        if(visited[y.first] == 2) continue;
        if(visited[y.first] == 1) {
            if(col[y.first] != !col[x]) {poss = false; return;}
        }
        col[y.first] = !col[x];
        visited[y.first] = 1;
        dfs(y.first);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj = vector<vector<pair<int, bool>>>(n);
    col = vector<bool>(n); visited = in = vector<int>(n);
    dag = vector<vector<int>>(n);

    for(int i = 0; i < m; i++) {
        int x, u, v; cin >> x >> u >> v;
        adj[--u].push_back({--v, x-1}), adj[v].push_back({u, x-1});
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        dfs(i);
    }
    if(!poss) {cout << "NO"; return;}

    for(int i = 0; i < n; i++) {
        for(auto j : adj[i]) {
            if(col[i] == j.second) {dag[i].push_back(j.first); in[j.first]++;}
            else {dag[j.first].push_back(i); in[i]++;}
        }
    }

    int left = n;
    queue<int> bfs;
    for(int i = 0; i < n; i++) if(!in[i]) {bfs.push(i); left--;}
    
    int on = 0;
    vector<int> ans(n);
    while(bfs.size()) {
        int x = bfs.front(); bfs.pop();
        ans[x] = on; on++;
        for(int y : dag[x]) {
            in[y]--;
            if(!in[y]) {bfs.push(y); left--;}
        }
    }

    if(left) {cout << "NO"; return;}
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        if(!col[i]) cout << "L ";
        else cout << "R ";
        cout << ans[i] << "\n";
    }

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