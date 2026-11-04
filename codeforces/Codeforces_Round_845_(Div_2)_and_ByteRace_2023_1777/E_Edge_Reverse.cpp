#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

vector<vector<pair<int, int>>> adj, adjT;
vector<int> ord, id;
vector<bool> vis;
int mid;

// calculates the order in which nodes are processed
void dfs1(int x) {
    vis[x] = true;
    for(auto y : adj[x]) if(!vis[y.first] && y.second <= mid) dfs1(y.first);
    ord.push_back(x);
};

// traverse one SCC at a time in reverse and
// assign component ID to all nodes in one SCC
void dfs2(int x, int col) {
    vis[x] = true;
    for(auto y : adjT[x]) if(!vis[y.first] && y.second <= mid) dfs2(y.first, col);
    id[x] = col;
};

void dfs3(int x){
    vis[x] = true;
    for(auto y : adj[x]) if(!vis[y.first] && y.second <= mid) dfs3(y.first);
};

void solve() {
    int n, m; cin >> n >> m;
    adj = vector<vector<pair<int, int>>>(n), adjT = vector<vector<pair<int, int>>>(n);;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[--u].push_back({--v, 0}); adj[v].push_back({u, w});
        adjT[u].push_back({v, w}); adjT[v].push_back({u, 0});
    }
    id = vector<int>(n);
    vis = vector<bool>(n);
 
    int l = 0, r = 1e9+1;
    while(l < r) {
        mid = (l+r-1)>>1;
 
        //init
        id.assign(n, 0);
        vis.assign(n, false);
        ord.clear();
        
        // cout << "asdf" << endl;
        //dfs1
        for(int i = 0; i < n; i++) if(!vis[i]) dfs1(i);
        vis.assign(n, false); reverse(ord.begin(), ord.end());
        
        // cout << "asdf" << endl;
        //dfs2
        int col = 0;
        for(int v : ord)
            if(!vis[v]) {
                dfs2(v, col); col++;
            }
 
        vis.assign(n, false);

        // cout << "asdf" << endl;
        bool work = true;
        for(int i = 0; i < n; i++) {
            if(!id[i]) {
                dfs3(i);
                for(bool x : vis)
                    if(!x) work = false;
                break;
            }
        }
 
        if(work) r = mid;
        else l = mid + 1;
    }
 
    if(l == 1e9+1) cout << -1;
    else cout << l;
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