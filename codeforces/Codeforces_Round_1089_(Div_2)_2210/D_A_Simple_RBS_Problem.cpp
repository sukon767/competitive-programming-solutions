#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<int> f;
vector<pair<int, bool>> p;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int x, int d, int s) {
    visited[x] = true;
    if(adj[x].size() - bool(x) >= 2) {
        if(!p[s].second) {p[s] = {d, 1};}
        else p[s].first = min(p[s].first, d);
    }
    if(adj[x].size() - bool(x) == 0) {
        if(!p[s].second) {p[s] = {d+1, 1};}
        else p[s].first = min(p[s].first, d+1);
        f[s]++;
    }
    for(int y : adj[x]) {if(!visited[y]) dfs(y, d+1, s);}
}

void solve() {
    int n; cin >> n;
    vector<string> s(2);
    for(string &i : s) cin >> i;
    for(string &x : s) x = '(' + x + ')';

    f = vector<int>(2);
    p = vector<pair<int, bool>>(2);    

    for(int j = 0; j < 2; j++) {     
        adj.clear();
        vector<int> stk;
        for(int i = 0; i < n+2; i++) {
            if(s[j][i] == '(') {
                stk.push_back(adj.size());
                adj.push_back({});
            } else {
                int cur = stk.back(); stk.pop_back();
                if(stk.size()) {
                    adj[cur].push_back(stk.back()); adj[stk.back()].push_back(cur);
                }
            }
        }
        visited = vector<bool>(adj.size());
        dfs(0, 0, j);
    }

    if(p[0] != p[1]) {cout << "NO"; return;}
    if(f[0] != f[1]) {cout << "NO"; return;}
    cout << "YES";
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