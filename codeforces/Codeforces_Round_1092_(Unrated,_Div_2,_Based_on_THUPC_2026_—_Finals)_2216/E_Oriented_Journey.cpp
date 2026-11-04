#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<vector<pair<int, bool>>> adj;
vector<bool> vis;
int n, ans;
void dfs(int x) {
    vis[x] = true;
    for(auto &p : adj[x]) {
        if(vis[p.first]) continue;
        if(bool(ans & (1LL << x)) != p.second) {
            ans |= (1LL << p.first);
        }
        dfs(p.first);
    }
}
 
void solve1() {
    cin >> n;
    int s; cin >> s;
    s %= (1LL << (n-1));
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        if(bool(s & (1LL << (u-1))) == bool(s & (1LL << (v-1)))) cout << v << " " << u << endl;
        else cout << u << " " << v << endl;
        // cout << (s&(1LL << (u-1))) << " " << (s&(1LL << (v-1))) << endl;
    }
}
 
void solve2() {
    cin >> n;
    ans = 0;
    adj = vector<vector<pair<int, bool>>>(n);
    vis = vector<bool>(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        bool b = false;
        if(u < v) {
            b = true;
        }
        adj[--u].push_back({--v, b}); adj[v].push_back({u, b});
    }
    dfs(n-1);
    if(!ans) cout << (1LL << (n-1)) << endl;
    else cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    int q; cin >> q;
    //int t = 1;
    while(t--) {
        if(q == 1) solve1();
        else solve2();
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