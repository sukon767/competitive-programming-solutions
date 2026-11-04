#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(auto& v : a) for(auto& i : v) cin >> i;

    vector<int> c(n); for(int i = 0; i < n; i++) c[i] = a[i][i];
    vector<vector<int>> adj(n);

    adj.push_back({});
    for(int i = 0; i < n; i++) adj.back().push_back(i);
    c.push_back(0);

    auto dfs = [&](auto&& self, int x, int pmx) -> void {
        int y = adj[x][0];
        int mx = 0;
        for(int i = 0; i < n; i++) if(a[y][i] < pmx) mx = max(mx, a[y][i]);
        c[x] = mx;
        // cout << x << " " << pmx << " " << y+1 << " " << mx << endl;
        vector<vector<int>> kid = {adj[x]};
        for(int j = 0; j < sz(kid); j++) {
            int z = kid[j][0];
            vector<int> t;
            for(int i = 0; i < sz(kid[j]); i++) {
                if(a[z][kid[j][i]] == mx) {
                    if(j+1==sz(kid)) kid.push_back({});
                    kid.back().push_back(kid[j][i]);
                } else t.push_back(kid[j][i]);
            }
            kid[j] = t;
        }
        adj[x].clear();
        for(int j = 0; j < sz(kid); j++) {
            if(sz(kid[j])>1) {
                adj[x].push_back(sz(adj)); adj.push_back(kid[j]); c.push_back(0);
                self(self, adj[x].back(), mx);
            } else adj[x].push_back(kid[j][0]);
        }

        // for(int x : kid[0]) cout << x+1 << " ";
        // cout << endl;
        // for(int x : kid[1]) cout << x+1 << " ";
        // cout << endl;
    };

    dfs(dfs, n, INT_MAX);

    cout << sz(adj) << "\n";
    for(int x : c) cout << x << " ";
    cout << "\n" << n+1 << "\n";
    for(int i = 0; i < sz(adj); i++) {
        for(int j : adj[i]) cout << j+1 << " " << i+1 << "\n";
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