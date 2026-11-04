#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n, {0, 0, 1}); //not used line, not used arch, used.
    vector<vector<vector<pair<int, int>>>> bt(n, vector<vector<pair<int, int>>>(3));
    vector<bool> vis(n);

    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = true;
        vector<int> co;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            //used
            int mn = min(dp[y][0], min(dp[y][1], dp[y][2]));
            dp[x][2]+=mn;
            for(int i = 0; i < 3; i++) {if(mn == dp[y][i]) {bt[x][2].push_back({y, i}); break;}}

            co.push_back(y);
        }

        if(!sz(co)) return;
        //not used line - might connect to some line and the rest are used
        int j = 0;
        for(int i = 1; i < sz(co); i++) if(dp[co[i]][0]-dp[co[i]][2] < dp[co[j]][0]-dp[co[j]][2]) j = i;
        bt[x][0].push_back({co[j], (dp[co[j]][0] > dp[co[j]][2] ? 2 : 0)});
        dp[x][0]+=dp[co[j]][(dp[co[j]][0] > dp[co[j]][2] ? 2 : 0)];
        for(int i = 0; i < sz(co); i++) {
            if(i==j) continue;
            bt[x][0].push_back({co[i], 2});
            dp[x][0]+=dp[co[i]][2];
        }

        if(sz(co) < 2) {dp[x][1] = INT_MAX>>1; return;}
        //not used arch - must connect to 2 lines and rest are used
        int j2 = -1;
        for(int i = 0; i < sz(co); i++) {
            if(i==j) continue;
            if(j2==-1 || dp[co[i]][0]-dp[co[i]][2] < dp[co[j2]][0]-dp[co[j2]][2]) j2 = i;
        }
        
        bt[x][1].push_back({co[j], 0});
        dp[x][1]+=dp[co[j]][0];
        bt[x][1].push_back({co[j2], 0});
        dp[x][1]+=dp[co[j2]][0];
        for(int i = 0; i < sz(co); i++) {
            if(i==j || i==j2) continue;
            bt[x][1].push_back({co[i], 2});
            dp[x][1]+=dp[co[i]][2];
        }
    };
    
    dfs(dfs, 0);

    // for(int i = 0; i < n; i++) {
    //     cout << i+1 << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    // }

    vector<pair<int, int>> ans;
    fill(vis.begin(), vis.end(), 0);
    vector<int> used(n);
    
    auto dfs2 = [&](auto&& self, int x, int s) -> void {
        vis[x] = true;
        // cout << x+1 << " " << s << endl;
        if(s==2) {
            ans.push_back({1, x+1});
            ans.push_back({2, x+1});
            used[x] = 1;
        }
        for(int y : adj[x]) {
            if(vis[y]) continue;
            for(auto&[y, s2] : bt[x][s]) self(self, y, s2);
        }
    };
    
    int mn = min(dp[0][0], min(dp[0][1], dp[0][2]));
    assert(mn <= n/4);
    for(int i = 0; i < 3; i++) if(dp[0][i]==mn) {dfs2(dfs2, 0, i); break;}

    vector<int> deg(n);
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        for(int j : adj[i]) {
            if(used[j] || j<i) continue;
            deg[i]++; deg[j]++;
        }
    }
    fill(vis.begin(), vis.end(), 0);

    auto dfs3 = [&](auto&& self, int x) -> void {
        vis[x] = true; ans.push_back({1, x+1}); used[x] = 2;
        for(int y : adj[x]) {
            if(vis[y] || used[y] == 1) continue;
            self(self, y);
        }
    };
    
    for(int i = 0; i < n; i++) {
        if(deg[i]<=1 && !used[i]) {
            dfs3(dfs3, i);
        }
    }

    cout << sz(ans) << "\n";
    for(auto&[a, b] : ans) cout << a << " " << b << "\n";
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