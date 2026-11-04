#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<bool> visited;
int ans;
vector<vector<pair<int, int>>> adj;

void dfs(int x) {
    visited[x] = true;

    for(pair<int, int> y : adj[x])
        if(!visited[y.first] && (y.second&ans) == y.second) dfs(y.first);
        // else cout << y.second << " " << ans << "\n";
}

int solve() {
    int n, m;
    cin >> n >> m;


    adj = vector<vector<pair<int, int>>>(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[--u].push_back({--v, w});
        adj[v].push_back({u, w});
    }

    ans = 0;
    for(int i = 30; i >= 0; i--) {
        ans += (1<<i)-1;
        visited = vector<bool>(n);
        dfs(0);
        ans -= (1<<i)-1;

        for(int j = 0; j < n; j++)  if(!visited[j]) {ans += (1<<i); 
            // cout << i << " " << j << "\n";
            break;}
    }

    cout << ans;
    
    

    return 0;



}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }




}