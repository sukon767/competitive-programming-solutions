#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

vector<vector<double>> dp;
vector<vector<int>> adj;
vector<bool> vis; 
string s;

void dfs(int x) {


    vis[x] = true;
    vector<int> cont;
    for(int y : adj[x]) {
        if(vis[y]) continue;
        dfs(y);
        cont.push_back(y);
    }
    sort(cont.begin(), cont.end(),
    [&](auto &x, auto &y) {
        return dp[x][0]-dp[x][1] < dp[y][0]-dp[y][1];
    });
    dp[x] = {INFINITY, INFINITY};
    for(int i = 0; i < 2; i++) {
        double ans = 0;
        if(s[x] == '1') {
            for(int y : cont) ans += dp[y][1];
            dp[x][i] = ans;
        } else {
            int deg = adj[x].size(), ideg = i;
            for(int y : cont) ans += dp[y][1];
            if(i) dp[x][i] = ans + double(deg)/ideg;
            for(int y : cont) {
                ans += dp[y][0] - dp[y][1];
                ideg++;
                if(ideg) dp[x][i] = min(dp[x][i], ans+double(deg)/ideg);
            }
        }
    }

    // cout << x << " " << dp[x][0] << " " << dp[x][1] << endl;
}

void solve() {
    int n; cin >> n;
    cin >> s;
    adj = vector<vector<int>>(n);
    vis.assign(n, false);
    dp = vector<vector<double>>(n);
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    dfs(0);
    cout << setprecision(20) << dp[0][0];
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