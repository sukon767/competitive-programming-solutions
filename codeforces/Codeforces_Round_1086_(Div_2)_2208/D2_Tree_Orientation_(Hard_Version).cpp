#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<string> s(n);
    for(string &i : s) cin >> i;

    for(int i = 0; i < n; i++) if(s[i][i] == '0') {cout << "No"; return;}
    
    vector<int> in(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(s[i][j] == '1') in[j]++;
        }

    queue<int> top;
    vector<bool> visited(n);
    for(int i = 0; i < n; i++) if(!in[i]) {top.push(i); visited[i] = true;}

    
    vector<int> topo, tinv(n);
    int left = n;
    while(top.size()) {
        int x = top.front(); top.pop();
        tinv[x] = topo.size(); topo.push_back(x);
        left--;
        // cout << x << endl;
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            if(i == x) continue;
            if(s[x][i] == '0') continue;

            in[i]--;
            if(!in[i]) {top.push(i); visited[i] = true;}
        }
    }

    if(left) {cout << "No"; return;}

    visited.assign(n, false);
    vector<vector<int>> adj(n);
    
    vector<int> par(n, -1);
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    };

    vector<vector<int>> check(n);
    for(int i = 0; i < n; i++) check[i].push_back(i);

    int ec = 0;

    for(int i = n-1; i >= 0; i--) {
        int x = topo[i];
        vector<vector<int>> cont(n);

        for(int j = 0; j < n; j++) {
            if(x == j || s[x][j] == '0') continue;
            cont[find(j)].push_back(j);
        }
        for(int j = 0; j < n; j++) {
            if(!cont[j].size()) continue;
            int ind = cont[j][0];
            for(int k = 1; k < cont[j].size(); k++) {
                if(tinv[cont[j][k]] < tinv[ind]) ind = cont[j][k];
            }
            adj[x].push_back(ind); ec++;
            for(int y : check[ind]) check[x].push_back(y);
            unite(x, ind);
        }

        for(int y : check[x]) {
            if(s[x][y] == '0') {cout << "No"; return;}
        }
        int cnt = 0;
        for(int j = 0; j < n; j++) if(s[x][j] == '1') cnt++;
        if(cnt != check[x].size()) {cout << "No"; return;}
    }

    if(ec != n-1) {cout << "No"; return;}
    
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
        for(int j : adj[i]) cout << i+1 << " " << j+1 << "\n";
            
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