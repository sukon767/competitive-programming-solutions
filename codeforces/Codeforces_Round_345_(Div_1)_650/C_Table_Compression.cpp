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
    vector<vector<int>> g(n, vector<int>(m));
    map<int, int> mp;
    for(auto& v : g) for(auto & i : v) {
        cin >> i;
    }

    vector<int> par(n*m, -1);
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    };

    for(int i = 0; i < n; i++) {
        vector<pair<int, int>> v;
        for(int j = 0; j < m; j++) v.push_back({g[i][j], i*m + j});
        sort(all(v));
        for(int i = 0; i+1 < sz(v); i++) {
            if(v[i].f == v[i+1].f) unite(v[i].s, v[i+1].s);
        }
    }

    for(int j = 0; j < m; j++) {
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({g[i][j], i*m + j});
        sort(all(v));
        for(int i = 0; i+1 < sz(v); i++) {
            if(v[i].f == v[i+1].f) unite(v[i].s, v[i+1].s);
        }
    }
    
    int N = 0;
    for(int i = 0; i < n*m; i++) {
        if(i == find(i)) {
            mp[i] = N; N++;
        }
    }
    for(int i = 0; i < n*m; i++) {
        mp[i] = mp[find(i)];
    }
    
    vector<vector<int>> adj(N)  ;
    vector<int> indeg(N);

    for(int i = 0; i < n; i++) {
        vector<pair<int, int>> v;
        for(int j = 0; j < m; j++) v.push_back({g[i][j], i*m + j});
        sort(all(v));
        for(int i = 0; i+1 < sz(v); i++) {
            if(v[i].f != v[i+1].f) {adj[mp[v[i].s]].push_back(mp[v[i+1].s]); indeg[mp[v[i+1].s]]++;}
        }
    }

    for(int j = 0; j < m; j++) {
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({g[i][j], i*m + j});
        sort(all(v));
        for(int i = 0; i+1 < sz(v); i++) {
            if(v[i].f != v[i+1].f) {adj[mp[v[i].s]].push_back(mp[v[i+1].s]); indeg[mp[v[i+1].s]]++;}
        }
    }
    
    vector<int> dp(N);
    queue<int> bfs;
    for(int i = 0; i < N; i++) {
        if(indeg[i]==0) {
            dp[i] = 1; bfs.push(i);
        } 
    }

    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop();
        for(int y : adj[x]) {
            dp[y] = max(dp[y], dp[x]+1);
            indeg[y]--;
            if(indeg[y]==0) bfs.push(y);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << dp[mp[i*m + j]] << " ";
        cout << "\n";
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