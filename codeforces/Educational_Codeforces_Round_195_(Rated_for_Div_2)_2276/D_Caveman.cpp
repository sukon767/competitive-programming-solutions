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
    //singleton -> brain melt
    //never 1? pls
    //all bipartite -> 2
    // otherwise many

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    for(int i = 0; i < n; i++) {
        if(adj[i].empty()) {
            cout << "Brain Melt"; return;
        }
    }

    vector<bool> vis(n);
    auto dfs = [&](auto&&self, int x) -> int {
        vis[x] = 1;
        //cnt of things with deg >1.
        int cnt = (deg[x]>1);
        for(int y : adj[x]) {
            if(vis[y]) continue;
            cnt += self(self, y);
        }
        return cnt;
    };


    int dfscnt = 0;
    int badcnt = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfscnt++;
            badcnt += dfs(dfs, i) > 1;
        }
    }

    cout << ((dfscnt > 1 || badcnt) ? "Many" : "2");
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