#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<vector<int>> adj;
vector<bool> vis;
vector<ll> a, dp;
ll ans;

void dfs(int x) {
    vis[x] = true;
    vector<ll> cont;
    for(int y : adj[x]) {
        if(vis[y]) continue;
        dfs(y);
        cont.push_back(dp[y]);
    }
    sort(cont.begin(), cont.end()); reverse(cont.begin(), cont.end());
    partial_sum(cont.begin(), cont.end(), cont.begin());

    dp[x] = a[x];
    ans = max(ans, a[x]);
    for(int i = 0; i < sz(cont); i++) {
        ans = max(ans, (i==1) ? cont[i] : cont[i]+a[x]);
        dp[x] = max(dp[x], (i==0) ? cont[i] : cont[i]+a[x]);
    }
}

void solve() {
    int n; cin >> n;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    dp = a = vector<ll>(n);
    ans = 0;

    for(ll& i : a) cin >> i;
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    dfs(0);

    cout << ans;
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