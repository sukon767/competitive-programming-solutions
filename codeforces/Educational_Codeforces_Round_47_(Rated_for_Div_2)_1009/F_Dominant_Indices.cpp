#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n);
    vector<vector<int>> d(n, {1});
    vector<pair<int, int>> ans(n, {1, 0});
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = 1;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            if(sz(d[y]) >= sz(d[x])) {
                ans[x] = max(ans[x], {ans[y].f, ans[y].s-1});
                d[y].push_back(1);
                for(int i = 1; i < sz(d[x]); i++) {
                    d[y][sz(d[y])-1-i] += d[x][sz(d[x])-1-i];
                    ans[x] = max(ans[x], {d[y][sz(d[y])-1-i], -i});
                }
                swap(d[x], d[y]);
            } else {
                for(int i = 0; i < sz(d[y]); i++) {
                    d[x][sz(d[x])-2-i] += d[y][sz(d[y])-1-i];
                    ans[x] = max(ans[x], {d[x][sz(d[x])-2-i], -(i+1)});
                }
            }
            vector<int>().swap(d[y]);
        }
    };

    dfs(dfs, 0);
    for(auto& [_, x] : ans) cout << -x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */