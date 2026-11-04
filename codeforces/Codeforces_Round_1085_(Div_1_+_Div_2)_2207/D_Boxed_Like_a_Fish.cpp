#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> val;
int n, k, v;
 
void dfs(int x) {
    
    visited[x] = true;
    vector<int> comp;
    for(int y : adj[x]) {
        if(visited[y]) continue;
        dfs(y);
        comp.push_back(val[y]);
    }

 
    if(comp.size() == 0) val[x] = 0;
    else if(comp.size() == 1) val[x] = comp[0]+1;
    else {
        // cout << x+1 << " b " << comp.size() << " " << comp[0] << " " << comp[1] << endl;

        sort(comp.begin(), comp.end());
        if(comp[0]+comp[1]+1 <= k) val[x] = 0;
        else val[x] = comp[0]+1;
    }

    // cout << x+1 << " " << val[x] << endl;

}
 
void solve() {
    cin >> n >> k >> v;
    --v;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    val = vector<int>(n);
    for(int i = 0; i < n-1; i++) {int u, v; cin >> u >> v; adj[--u].push_back(--v), adj[v].push_back(u);}
    dfs(v);
 
    if(!val[v]) cout << "YES";
    else cout << "NO";
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