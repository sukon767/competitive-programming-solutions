#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

vector<bool> visited;
int n;
map<pair<int, int>, int> ind;
vector<vector<int>> adj;
vector<int> ans;

void dfs(int x, bool p) {
    visited[x] = true;
    for(auto y : adj[x]) {
        if(!visited[y]) {
            if(!p) {ans[ind[{x, y}]] = n+y, ans[y] = y;}
            else {ans[ind[{x, y}]] = y, ans[y] = n+y;}
            dfs(y, !p);
        }
    }
}
 
void solve() {
    int p; cin >> p;
    n = (1 << p);
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u); ind[{u, v}] = n+i, ind[{v, u}] = n+i;
    }
    ans = vector<int>(2*n-1); ans[0] = n;

    dfs(0, false);
    
    cout << 1 << "\n";
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << "\n";
    for(int i = n; i < 2*n-1; i++) cout << ans[i] << ' ';
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