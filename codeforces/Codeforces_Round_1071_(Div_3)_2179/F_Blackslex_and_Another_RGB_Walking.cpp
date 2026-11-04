#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    vector<int> d(n);
    vector<bool> visited(n);
    queue<pair<int, int>> bfs;
    visited[0] = true;
    bfs.push({0, 0});
    while(bfs.size()) {
        int x = bfs.front().first; int dx = bfs.front().second;
        d[x] = dx;
        for(int y : adj[x]) if(!visited[y]) {visited[y] = true; bfs.push({y, dx+1});}
        bfs.pop();
    }

    for(int i = 0; i < n; i++) {
        if(d[i]%3 == 0) cout << 'r';
        else if(d[i]%3 == 1) cout << 'g';
        else cout << 'b';
    }
}

void solve2() {
    int q;  cin >> q;
    // cout << q << "\n";
    for(int b = 0; b < q; b++) {
        int dv; cin >> dv;
        string c; cin >> c;
        char x1, x2;
        int i2 = 0;
        x1 = c[0];
        for(int i = 1; i < dv; i++) {
            if(c[i] != x1) {x2 = c[i]; i2 = i+1;}
        }

        if(dv == 1 || i2 == 0)  {cout << 1 << "\n"; continue;}

        if('r' != x1 && 'r' != x2) {
            if(x1 == 'b') cout << 1;
            else cout << i2;
        } else if ('g' != x1 && 'g' != x2) {
            if(x1 == 'r') cout << 1;
            else cout << i2;
        } else {
            if(x1 == 'g') cout << 1;
            else cout << i2;
        }
        cout << "\n";
    }
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    string x; cin >> x;
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(x == "first") {
            if(i) cout << "\n";
            solve();
        }
        else
            solve2();
    }
}