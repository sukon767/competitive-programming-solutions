#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n), kid(n);
    for(int i = 0; i+1 < n; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<int> f(n+1), dp(n);
    vector<vector<int>> lvl(n+1);
    auto dfs = [&](auto&& self, int x, int d) -> void {
        vis[x] = 1; f[d]++; dp[x] = d; lvl[d].push_back(x);
        for(int y : adj[x]) {
            if(vis[y]) continue;
            kid[x].push_back(y);
            self(self, y, d+1);
        }
    };
    dfs(dfs, 0, 0);

    vector<int> left(n);
    for(int i = 0; i < n; i++) left[i] = sz(kid[i]);

    vector<int> pt(n, -1);
    for(auto& v : lvl) sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {return sz(kid[a]) > sz(kid[b]);});
    
    for(int i = 0; i <= n; i++) {
        int fw = 0;
        int s = sz(lvl[i]);
        if(s<=1) continue;
        for(int j = 0; j < s; j++) {
            // if(i==4) cout << i << " " << j << endl;
            int u = lvl[i][j], v = lvl[i][(j+1)%s];
            if(left[v]) {left[v]--; pt[u] = kid[v][left[v]];}
            else {
                while(fw < j && !left[lvl[i][fw]]) fw++;
                if(fw==j) continue;
                v = lvl[i][fw];
                left[v]--; pt[u] = kid[v][left[v]]; 
            }
        }
    }
    
    // cout << "asdf" << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << i+1 << " " << pt[i]+1 << endl;
    // }


    fill(vis.begin(), vis.end(), 0);
    set<vector<int>> cur; //depth, -size, node
    for(int j = 0; j <= n; j++) {
        for(int i : lvl[j]) {
            if(!vis[i]) {
                int x = i;
                int s = 0;
                while(x != -1) {vis[x] = 1; x = pt[x]; s++;}
                cur.insert({dp[i], -s, i});
            }
        }
    }

    // for(auto&v : cur) cout << v[0] << " " << v[1] << " " << v[2] << endl;

    vector<vector<int>> op(1);
    int curd = 0;
    while(sz(cur)) {
        auto it = cur.lower_bound({curd, INT_MIN, INT_MIN});
        if(it == cur.end()) {
            op.push_back(vector<int>());
            curd = 0;
        } else {
            int x = (*it)[2];
            curd = dp[x];
            while(x != -1) {op.back().push_back(x); curd++; x = pt[x];}
            curd++;
            cur.erase(it);
        }
    }


    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, f[i]);
    for(int i = 0; i < n; i++) {
        if(sz(kid[i]) == f[dp[i]+1]) ans = max(ans, f[dp[i]+1]+1);
    }
    assert(ans == sz(op));
    cout << ans << "\n";
    for(auto& v : op) {
        cout << sz(v);
        for(int i = 0; i < sz(v); i++) cout << " " << v[i]+1;
        cout << "\n";
    }
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