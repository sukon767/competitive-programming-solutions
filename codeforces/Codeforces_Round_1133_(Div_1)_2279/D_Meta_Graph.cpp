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
    int w, x, y, z; cin >> w >> x >> y >> z;
    w--, x--, y--, z--;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back({--v, 1});
        adj[v].push_back({u, 1});
    }
    
    auto doit = [](int x, vector<vector<pair<int, int>>>& adj) {
        int n = sz(adj);
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[x] = 0;
        pq.push({0, x});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dis[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    };

    vector<int> d0 = doit(x, adj);
    vector<int> dn = doit(z, adj);


    vector<vector<pair<int, int>>> adj2(n);
    for(int i = 0; i < n; i++) {
        if(i == w) {
            for(auto [v, _] : adj[w]) {
                if(v == y) continue;
                adj2[w].push_back({v, d0[v]});
            }
        } else if(i == y) {
            for(auto [v, _] : adj[y]) {
                if(v == w) continue;
                adj2[y].push_back({v, dn[v]});
            }
        } else {
            for(auto [v, _] : adj[i]) {
                if(v == w) adj2[i].push_back({w, d0[i]});
                else if(v == y) adj2[i].push_back({y, dn[i]});
                else adj2[i].push_back({v, 3});
            }
        }
    }
    int ans = INT_MAX;
    if(w != y) {
        vector<int> fin = doit(w, adj2);
        if(fin[y] != INT_MAX) ans = min(ans, fin[y] + 4);
    }

    for(auto [v, _] : adj[w]) {
        if(v == y) ans = min(ans, d0[y] + dn[w] + 1);
    }
    if(w == y) ans = min(ans, d0[z]);

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