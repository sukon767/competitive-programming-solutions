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
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    vector<int> cur(n, INT_MAX>>1); cur[0]=0;
    int t = 0;
    while(cur.back()==INT_MAX>>1) {
        vector<int> nd(n, INT_MAX>>1);
        for(int i = 0; i < n; i++) {
            int to = adj[i][t%sz(adj[i])];
            nd[to] = min(nd[to], cur[i]);
            nd[i] = min(nd[i], cur[i]+1);
        }
        cur = nd;
        t++;
    }

    cout << t << " " << cur.back();
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