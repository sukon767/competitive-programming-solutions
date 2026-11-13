#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    vector<int> dis(n);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(int y : adj[x]) {
            if(y == p) continue;
            dis[y] = dis[x]+1;
            self(self, y, x);
        }
    };
    dfs(dfs, n-1, -1);

    vector<bool> st(n);
    auto dfs2 = [&](auto &&self, int x, int p) -> void {
        st[x] = x==n-1;
        for(int y : adj[x]) {
            if(y == p) continue;
            self(self, y, x);
            st[x] = st[x] || st[y];
        }
    };
    dfs2(dfs2, 0, -1);

    auto dfs3 = [&](auto &&self, int x) -> void {
        for(int y : adj[x]) {
            if(st[y] || y == 0) continue;
            st[y] = 1;
            self(self, y);
        }
    };
    for(int i = 1; i < n; i++) if(st[i]) dfs3(dfs3, i);


    int ans = dis[0];
    while(m--) {
        int v; cin >> v; v--;
        if(st[v]) ans = max(ans, 1 + dis[v]);
    }
    cout << ans;
}

//king of the sun o_O
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */