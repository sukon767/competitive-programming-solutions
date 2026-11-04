#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> cyc;
    vector<int> vis(n);
    vector<int> path;
    auto dfs = [&](auto&& self, int x, int par) -> void {
        vis[x] = 1; path.push_back(x);
        for(int y : adj[x]) {
            if(vis[y]) {
                if(vis[y]==1 && y != par) {
                    int l = sz(path)-1;
                    pair<int, int> ad = {y, y};
                    while(path[l] != y) {
                        ad = {min(ad.first, path[l]), max(ad.second, path[l])};
                        l--;
                    }
                    cyc.push_back(ad);
                }
                continue;
            }
            self(self, y, x);
        }
        vis[x] = 2; path.pop_back();
    };
    
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(dfs, i, -1);
    }

    sort(cyc.begin(), cyc.end(), [&](const auto& a, const auto& b) {if(a.first == b.first) return a.second > b.second; return a.first < b.first;});
    vector<pair<int, int>> t;
    for(int i = 0; i < sz(cyc); i++) {
        while(sz(t) && t.back().second >= cyc[i].second) t.pop_back();
        t.push_back(cyc[i]);
    }
    
    vector<ll> pre(n), till(n, n-1);
    for(int i = 0; i < n; i++) pre[i] = n-i;
    for(int i = 0; i < sz(t); i++) {
        for(int j = (i ? t[i-1].first+1 : 0); j <= t[i].first; j++) {
            pre[j] = t[i].second-j;
            till[j] = t[i].second-1;
        }
    }

    partial_sum(pre.begin(), pre.end(), pre.begin());
    
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r; l--; r--;
        ll lb = max(l, (ll)distance(till.begin(), upper_bound(till.begin(), till.end(), r)));
        ll ans = (lb ? pre[lb-1] : 0) - (l ? pre[l-1] : 0) + (r-lb+1)*(r-lb+2)/2;
        cout << ans << "\n";
    }
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