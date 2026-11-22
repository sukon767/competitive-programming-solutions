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
    vector<pair<int, int>> del, path;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    vector<int> dp(n, -1);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        vector<int> ukid;
        for(int y : adj[x]) {
            if(y == p) continue;
            self(self, y, x);
            if(dp[y] != -1) ukid.push_back(y);
        }
        if(sz(ukid) >= 2) {
            path.push_back({dp[ukid[0]], dp[ukid[1]]});
            if(p != -1) del.push_back({x, p});
            for(int i = 2; i < sz(ukid); i++) {
                path.push_back({ukid[i], dp[ukid[i]]});
                del.push_back({ukid[i], x});
            }
        } else if(sz(ukid) == 1) dp[x] = dp[ukid[0]];
        else dp[x] = x;
    };
    dfs(dfs, 0, -1);
    if(dp[0] != -1) {
        path.push_back({dp[0], 0});
    }

    assert(sz(path) == sz(del)+1);
    cout << sz(del) << "\n";
    for(int i = 0; i < sz(del); i++) {
        cout << del[i].f+1 << " " << del[i].s+1 << " " << path[i].s+1 << " " << path[i+1].f+1 << "\n";
    }
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