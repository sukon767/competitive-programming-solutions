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
    vector<vector<pair<int, int>>> adj(n);

    vector<array<ll, 3>> edges;
    for(int i = 0; i+1 < n; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[--a].push_back({--b, w});
        adj[b].push_back({a, w});
        edges.push_back({w, a, b});
    }
    sort(all(edges));

    vector<int> deg(n);
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        deg[--a]++; deg[--b]++;
    }

    ll cost = 0;
    vector<int> cnt(n);
    auto dfs = [&](auto&& self, int x, int p) -> int {
        int parity = deg[x]&1;
        for(auto [y, w] : adj[x]) {
            if(y == p) continue;
            int y_parity = self(self, y, x);
            if(y_parity) {
                parity ^= 1;
                cost += w;
            }
        }
        return parity;
    };
    dfs(dfs, 0, -1);
    cout << cost;
}

//king of the sun o_O
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