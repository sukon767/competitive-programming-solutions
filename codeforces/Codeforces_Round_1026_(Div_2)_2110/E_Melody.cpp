#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

vector<vector<pair<int, int>>> adj;
vector<bool> seen;
vector<int> path;

void dfs(int x) {
    while(adj[x].size()) {
        auto [y, e] = adj[x].back();
        adj[x].pop_back();
        if(seen[e]) continue;
        seen[e] = true;
        dfs(y);
        path.push_back(e);
    }
}
 
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    vector<int> s1, s2;
    for(auto &[v, p] : vp) {
        cin >> v >> p;
        s1.push_back(v), s2.push_back(p);
    }

    sort(s1.begin(), s1.end()), sort(s2.begin(), s2.end());
    s1.erase(unique(s1.begin(), s1.end()), s1.end()), s2.erase(unique(s2.begin(), s2.end()), s2.end());
    map<int, int> t1, t2;
    for(int i = 0; i < s1.size(); i++) t1[s1[i]] = i;
    for(int i = 0; i < s2.size(); i++) t2[s2[i]] = i+s1.size();

    int m = s1.size() + s2.size();
    adj = vector<vector<pair<int, int>>>(m);
    vector<int> deg(m);
    
    for(int i = 0; i < n; i++) {
        int x = t1[vp[i].first], y = t2[vp[i].second];
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        deg[x]++; deg[y]++;
    }

    vector<int> ext;
    for(int i = 0; i < m; i++) {
        if(deg[i]%2) {
            if(ext.size() == 2) {cout << "NO"; return;}
            ext.push_back(i);
        }
    }

    seen = vector<bool>(n);
    if(ext.size() == 1) {cout << "NO"; return;}
    if(ext.size() == 2) {
        adj[ext[0]].push_back({ext[1], n});
        adj[ext[1]].push_back({ext[0], n});
        seen.push_back(0);
    }

    path.clear();
    dfs(0);

    if(path.size() != seen.size()) {cout << "NO"; return;}

    int s = 0;
    if(ext.size()) {
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == n) {s = i; break;}
        }
    }

    cout << "YES\n";
    for(int i = s+1; i < s+1+n; i++) {
        cout << path[i%path.size()]+1 << " ";
    }

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