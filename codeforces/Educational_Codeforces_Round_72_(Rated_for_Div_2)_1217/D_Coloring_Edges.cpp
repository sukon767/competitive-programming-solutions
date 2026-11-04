#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<int> visited;
bool done = false;
vector<vector<int>> adj;


void dfs(int x) {
    if(done) return;

    for(int y : adj[x]) {
        if(visited[y] == 1) {done = true; return;}
        if(visited[y] == 2) {continue;}
        visited[y] = 1; dfs(y);
    }
    
    visited[x] = 2;
} 

void solve() {
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n); visited = vector<int>(n);
    vector<pair<int, int>> sl;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        sl.push_back({u, v});
    }
    // cout << "asdf" << endl;

    for(int i = 0; i < n; i++)
        if(!visited[i]) dfs(i);

            // cout << "asdf" << endl;


    if(done) {
        // cout << "asdf1" << endl;
        cout << 2 << "\n";
        for(int i = 0; i < m; i++) {if(i) cout << " "; if(sl[i].first < sl[i].second) cout << 1; else cout << 2;}
    } else {
        // cout << "asdf2" << endl;
        cout << 1;
        for(int i = 0; i < m; i++) cout << " " << 1;
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}