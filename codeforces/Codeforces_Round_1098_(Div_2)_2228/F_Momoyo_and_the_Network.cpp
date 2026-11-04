#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    ll tot = 0;
    for(int& i : a) {
        cin >> i; tot += i;
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    vector<int> dp(n);
    vector<ll> sum(n);
    vector<bool> vis(n);

    auto dfs1 = [&](auto&& self, int x) -> void {
        vis[x] = true; sum[x] = a[x];
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            sum[x] += sum[y];
        }
    };

    auto dfs = [&](auto&& self, int x, ll m) -> bool {
        vis[x] = true;
        vector<int> cont;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            if(self(self, y, m)) return true;
            cont.push_back(y);
        }

        if(sum[x] >= m) dp[x] = max(dp[x], 0);

        if(!sz(cont)) return false;
        
        sort(cont.begin(), cont.end(), [&](const int& a, const int& b) {return dp[a] < dp[b];});
        int l = sz(cont);
        ll mins = LLONG_MAX>>1;

        for(int r = 0; r < sz(cont); r++) {
            if(sum[x]-sum[cont[r]] >= m) dp[x] = max(dp[x], 1+dp[cont[r]]);
            //check line
            if(dp[cont[r]]+1 >= k && tot-sum[cont[r]] >= m) return true;

            //check using both
            if(!r || dp[cont[r]]+dp[cont[r-1]]+2 < k) continue;
            
            mins = min(mins, sum[cont[r-1]]);
            l = min(l, r-1);
            
            while(l && dp[cont[l-1]]+dp[cont[r]]+2 >= k) {
                l--;
                mins = min(mins, sum[cont[l]]);
            }

            if(tot-sum[cont[r]]-mins >= m) {
                return true;
            }
        }

        return false;
    };

    dfs1(dfs1, 0);
    // ll l = 3, r = 4;
    ll l = -1, r = 2e14;
    while(l < r) {
        ll m = (l+r+1)>>1;
        fill(dp.begin(), dp.end(), -1); fill(vis.begin(), vis.end(), 0);
        if(dfs(dfs, 0, m)) l = m;
        else r = m-1;
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