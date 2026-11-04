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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    //answer: (#odd-even in comp choose 2) + (#odd - #oddcomp)
    vector<bool> vis(n);
    ll tos = 0;
    int otot = 0;

    int oddsum = 0;
    int compsz = 0;

    auto dfs = [&](auto &&self, int x) -> void {
        vis[x] = 1;
        compsz++;
        for(int y : adj[x]) {
            oddsum += deg[y]&1;
            if(vis[y] || (deg[y]&1) != (deg[x]&1)) continue;
            self(self, y);
        }
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i] && !(deg[i]&1)) {
            dfs(dfs, i);
            tos+=(ll)oddsum*(oddsum-1)/2;
            oddsum = compsz = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i] && (deg[i]&1)) {
            dfs(dfs, i);
            otot+=compsz-1;
            oddsum = compsz = 0;
        }
    }

    cout << tos + otot;
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