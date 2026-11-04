#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<vector<int>> adj;
vector<bool> vis;
vector<int> s;
int n, k, val;

int dfs(int x) {
    vis[x] = 1;
    int ans = 0;
    for(int y : adj[x]) {
        if(vis[y]) continue;
        ans += dfs(y);
        s[x] += s[y];
    }
    s[x]++;
    if(s[x] >= val) {
        s[x] = 0;
        ans++;
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    s = vector<int>(n);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    int l = 1, r = n;
    while(l < r) {
        val = (l+r+1)>>1;
        vis.assign(n, 0); s.assign(n, 0);
        if(dfs(0) >= k+1) l = val;
        else r = val-1;
    }

    cout << l;
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