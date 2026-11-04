#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> lr(n);
    for(auto& p : lr) cin >> p.first >> p.second;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    ll ans = 0;
    vector<ll> val(n);
    vector<int> vis(n);
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        vector<ll> lis;
        ll mx = 0;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            lis.push_back(val[y]);
            mx = max(mx, val[y]);
        }
        val[x] = max(lr[x].first, min(lr[x].second, mx));
        for(ll dy : lis) ans += max(0LL, dy - val[x]);
    };
    dfs(dfs, 0);

    cout << val[0] + ans;
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */