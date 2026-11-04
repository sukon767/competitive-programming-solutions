#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n); vector<int> out(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--v].push_back(--u); out[u]++;
    }
    priority_queue<int> ts;
    for(int i = 0; i < n; i++) if(!out[i]) ts.push(i);
    vector<int> p;
    while(ts.size()) {
        int x = ts.top();
        ts.pop();
        p.push_back(x+1);
        for(int k : adj[x]) {
            out[k]--;
            if(!out[k]) ts.push(k);
        }
    }
    for(int i = n-1; i >= 0; i--) cout << p[i] << " ";
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
