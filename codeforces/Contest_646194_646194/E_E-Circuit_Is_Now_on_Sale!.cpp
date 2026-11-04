#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, m; cin >> n >> m;
    int P;
    vector<char> pt(n*m);
    vector<vector<int>> adj(n*m);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) pt[i*m + j] = s[j];
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = m*i+j;
            if(pt[u] != '.') {
                for(int r = -1; r <= 1; r++) {
                    for(int s = -1; s <= 1; s++) {
                        if(bool(r) == bool(s)) continue;
                        if(i+r < 0 || i+r >= n || j+s < 0 || j+s >= m) continue;
                        int v = m*(i+r) + (j+s);
                        if(pt[v] != '.') adj[u].push_back(v);
                    }
                }
                if(pt[u] == 'P') P = u;
            }
        }
    }

    
    vector<bool> vis(n*m);
    vector<ll> ot(n*m);
    auto dfs = [&](auto&& self, int x) -> void {
        vector<ll> cc;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            vis[y] = 1;
            self(self, y);
            cc.push_back(ot[y]);
        }

        if(pt[x] == '#' || pt[x] == 'P') ot[x] = cc[0];
        else if(pt[x] == '+') ot[x] = cc[0]+cc[1];
        else if(pt[x] == '-') ot[x] = abs(cc[0]-cc[1]);
        else if(pt[x] == '*') ot[x] = cc[0]*cc[1];
        else if(pt[x] == '/') ot[x] = max(cc[0]/cc[1], cc[1]/cc[0]);
        else ot[x] =  pt[x] - '0';
    };
    
    vis[P] = 1;
    dfs(dfs, P);
    cout << ot[P];
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