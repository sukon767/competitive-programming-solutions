#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<vector<int>> adj, dp;
int anz = 0;

void dfs(int s) {
    for(int x = s-1; x >= 0; x--) {
        int c1 = -1, c2 = -1, c3 = -1; 
        for(int y : adj[x]) {
            if(y >= s) continue;
            if(c1 == -1 || dp[y][0] > dp[c1][0]) {c3 = c2, c2 = c1, c1 = y;}
            else if(c2 == -1 || dp[y][0] > dp[c2][0]) {c3 = c2, c2 = y;}
            else if(c3 == -1 || dp[y][0] > dp[c3][0]) c3 = y;
        }
    
        dp[x][1] = c1;
        dp[x][2] = c2;
        dp[x][3] = c3;
        
        dp[x][0] = 1 + (dp[x][2]==-1 ? 0 : dp[dp[x][2]][0]);
    }

    for(int x = 0; x < s; x++) {
        //update anz
        pair<int, int> cont = {dp[x][4], -1};
        for(int i = 1; i < 4; i++) 
            if(dp[x][i] != -1) {
                if(dp[dp[x][i]][0] > cont.first) cont = {dp[dp[x][i]][0], cont.first};
                else if(dp[dp[x][i]][0] > cont.second) cont.second = dp[dp[x][i]][0];
            }
        anz = max(anz, 1 + (cont.second==-1 ? 0 : cont.second));
        
        
        for(int y : adj[x]) {
            if(y >= s) continue;
            //update children's up
            pair<int, int> cont = {dp[x][4], -1};
            for(int i = 1; i < 4; i++) 
                if(dp[x][i] != -1 && dp[x][i] != y) {
                    if(dp[dp[x][i]][0] > cont.first) cont = {dp[dp[x][i]][0], cont.first};
                    else if(dp[dp[x][i]][0] > cont.second) cont.second = dp[dp[x][i]][0];
                }
            dp[y][4] = 1 + (cont.second==-1 ? 0 : cont.second);
        }
    }
}

void solve() {
    int n; cin >> n; n++;
    adj = vector<vector<int>>(n);
    dp = vector<vector<int>>(n, vector<int>(5, -1)); //itself, c1, c2, c3, up.
    for(int i = 0; i < n; i++) dp[i].back() = 0;
    
    for(int i = 0; i < n-1; i++) {
        int u; cin >> u;
        adj[--u].push_back(i+1);
    }
    vector<int> ans(20);
    for(int j = 1; j < 20; j++) {
        int lo = 0, hi = n-1;
        while(lo < hi) {
            int m = (lo+hi)>>1;
            
            dfs(m+2);
            
            if(anz >= j) hi = m;
            else lo = m+1;

            for(auto& v : dp) {fill(v.begin(), v.end(), -1); v.back() = 0;}
            anz = 0;
        }

        ans[j] = lo;
    }

    for(int i = 1; i < 20-1; i++) {
        for(int j = ans[i]; j < ans[i+1]; j++) cout << i << " ";
    }
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