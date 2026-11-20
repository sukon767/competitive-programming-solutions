#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve1() {

    // first
    // 3
    // 4
    // 101
    // 3
    // 11
    // 4
    // 000

    int n; cin >> n;
    string s; cin >> s;
    s = '0' + s;
    vector<pair<int, int>> adj;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(s[i] != s[j]) {
                adj.push_back({i, j});
            }
        }
    }
    
    if(adj.empty()) {
        for(int i = 0; i < 3; i++) {
            adj.push_back({i, (i+1)%3});
        }
        for(int i = 2; i+1 < n; i++) adj.push_back({i, i+1});
    }

    cout << sz(adj) << "\n";
    for(auto &p : adj) cout << p.f+1 << " " << p.s+1 << "\n";
}
void solve2() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    vector<bool> col(n);
    vector<bool> vis(n);
    
    auto dfs = [&](auto &&self, int x) -> bool {
        for(int y : adj[x]) {
            if(vis[y] && col[y] == col[x]) {
                return 0;
            }
            if(vis[y]) continue;
            vis[y] = 1; col[y] = !col[x];
            if(!self(self, y)) return 0;
        }
        return 1;
    };
    if(!dfs(dfs, 0)) {
        for(int i = 0; i < n-1; i++) cout << '0';
        return;
    }

    for(int i = 1; i < n; i++) {
        cout << col[i];
    }
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        if(s == "first") solve1();
        else solve2();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */