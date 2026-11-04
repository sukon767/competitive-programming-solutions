#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    //  cout << "asdf\n";

    vector<pair<int, int>> depth(n);
    for(int i = 0; i < n; i++)  depth[i].second = i;
    vector<bool> visited(n);
    queue<pair<int, int>> bfs;

    bfs.push({0, 0}); 
    int on = 0;

    //  cout << "asdf\n";

    vector<int> par(n);

    while(bfs.size()) {
        
        while(bfs.size() && bfs.front().second == on) {


            pair<int, int> cur = bfs.front();
            visited[cur.first] = true;
            depth[cur.first].first = on;

            // cout << cur.first << " " << cur.second << "\n";

            for(int x : adj[cur.first])
                if(!visited[x]) {
                    bfs.push({x, on+1});
                    par[x] = cur.first;
                }

            bfs.pop();
        }

        on++;
    }

    sort(depth.begin(), depth.end());

    vector<bool> onPath(n);

    // cout << "asdf\n";

    int trav = n-1;
    while(trav) {
        onPath[trav] = true;
        trav = par[trav];
    }
    onPath[0] = true;

    vector<vector<int>> ans;

    int pa = 0;
    
    // for(int i = 0; i < n; i++)  
    //     if(onPath[i])   cout << i << " asdf\n";


    for(int i = n-1; i >= 0; i--) {
        if(onPath[depth[i].second])   continue;

        if(pa == (depth[i].first%2)) {
            ans.push_back({1});
            pa = (pa+1)%2;
        }

        ans.push_back({2, depth[i].second+1});

        pa = (pa+1)%2;
        ans.push_back({1});

    }

    for(int i = 0; i < n; i++) {
        if(!onPath[depth[i].second] || depth[i].second == n-1)  continue;

        // cout << "curpa " << pa << " " << depth[i].second << '\n';
        
        if(pa == (depth[i].first%2)) {
            ans.push_back({1});
            pa = (pa+1)%2;
        }

        ans.push_back({2, depth[i].second+1});

        pa = (pa+1)%2;
        ans.push_back({1});
    }

    cout << ans.size();
    for(int i = 0; i < ans.size(); i++) {
        cout << "\n";
        for(int j = 0; j < ans[i].size(); j++) {
            if(j)   cout << " ";
            cout << ans[i][j];
        }
    }


    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}