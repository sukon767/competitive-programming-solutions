#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n); vector<int> in(n);
    for(int i = 0; i < n-1; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        if(x <= y) {adj[--u].push_back(--v); in[v]++;}
        else {adj[--v].push_back(--u); in[u]++;}
    }

    queue<int> ts;
    for(int i = 0; i < n; i++) if(!in[i]) ts.push(i);
    int on = 1;
    vector<int> p(n);

    while(ts.size()) {
        int x = ts.front();
        p[x] = on; on++;
        for(int k : adj[x]) {
            in[k]--;
            if(!in[k]) ts.push(k);
        }
        ts.pop();
    }

    for(int i = 0; i < n; i++) cout << p[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}