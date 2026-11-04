#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<bool> visited;
vector<vector<int>> adj;

int stop;
ll cnt;

void dfs(int x) {
    visited[x] = true;  cnt++;
    if(x == stop)   return;
    for(int kid : adj[x])   if(!visited[kid])   dfs(kid);
}

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    a--; b--;
    adj = vector<vector<int>>(n);   visited = vector<bool>(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >>v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    ll ans = 1;
    stop = b;
    cnt = 0;
    dfs(a);
    ans *= n-cnt;

    visited = vector<bool>(n);
    stop = a;
    cnt = 0;
    dfs(b);
    ans *= n-cnt;

    cout << ans;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}