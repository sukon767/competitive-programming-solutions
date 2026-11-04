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
    ll n, m, q, p; cin >> n >> m >> q >> p;
    vector<string> grid(n); for(string &s : grid) cin >> s;
    vector<vector<ll>> val(n, vector<ll>(m));

    vector<int> vis(n*m, 0);
    vector<int> lst;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != '.' && grid[i][j] != '*') {
                ll ns = q*(grid[i][j]-'A'+1);
                queue<pair<int, int>> bfs; bfs.push({i*m+j, 0});
                vis[i*m+j] = 1;
                lst.push_back(i*m+j);
                val[i][j] += ns;
                while(sz(bfs)) {
                    auto [x, dis] = bfs.front(); bfs.pop();
                    int l = x/m, r = x%m;
                    dis++;
                    if((1LL<<dis) > ns) continue;
                    for(int u = -1; u <= 1; u++) {
                        for(int v = -1; v <= 1; v++) {
                            if(bool(u) + bool(v) != 1) continue;
                            int y = (l+u)*m + (r+v);
                            if(0 <= l+u && l+u < n && 0 <= r+v && r+v < m && !vis[y] && grid[l+u][r+v] != '*') {
                                bfs.push({y, dis});
                                vis[y] = 1;
                                lst.push_back(y);
                                val[l+u][r+v] += (ns>>dis);
                            }
                        }
                    }
                }
                for(int x : lst) vis[x] = 0;
                lst.clear();
            }
        }
    }

    int ans = 0;
    for(auto &w : val) {
        for(auto &x : w) {
            // cout << x << " ";
            ans += (x>p);
        }
        // cout << "\n";
    }
    cout << ans;
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