#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> ans;
    vector<set<int>> adj(n);
    for(int i =0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].insert(--v);
        adj[v].insert(u);
    }    

    for(int i = 0; i < n; i++) {
        while(adj[i].size() >= 2) {
            int u = *adj[i].begin(); 
            adj[i].erase(u);    adj[u].erase(i);
            int v = *(adj[i].begin());
            adj[i].erase(v);    adj[v].erase(i);
            if(adj[u].find(v) != adj[u].end()) {
                adj[u].erase(v); adj[v].erase(u);
            } else {
                adj[u].insert(v); adj[v].insert(u);
            }

            ans.push_back({i, u, v});
        }
    }

    vector<int> d(n, -1);
    function<int(int)> find = [&](int x) {return d[x] < 0 ? x : d[x] = find(d[x]);};
    function<bool(int, int)> unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return 1;
    };

    int cct = n;
    int c = 0;
    for(int i = 0; i < n; i++)
        for(int j : adj[i]) {
            cct -= unite(i, j); c = i;
        }   
            

    if(cct < n) {
        for(int i = 0; i < n; i++) {
            if(i == c)   continue; 
            if(find(c) != find(i)) {
                int u;
                if(adj[c].size()) {
                    u = *adj[c].begin();
                    adj[c].erase(u); adj[u].erase(c);
                    adj[i].insert(u); adj[u].insert(i);
                } else {
                    u = *adj[i].begin();
                    adj[i].erase(u); adj[u].erase(i);
                    adj[c].insert(u); adj[u].insert(c);
                }
                
                adj[i].insert(c); adj[c].insert(i);
                
                ans.push_back({i, c, u});
                // cout << "sdf " << i << " " << c << " " << u << "\n";
                unite(i, c);
            }
        }
    }
    

    cout << ans.size();
    for(int i = 0; i < ans.size(); i++) {
        cout << "\n";
            for(int j = 0; j < 3; j++) {
                if(j)   cout << " ";
                cout << ans[i][j]+1;
            }
    }

    
        
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}