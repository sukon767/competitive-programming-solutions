#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int k; cin >> k;
    vector<pair<vector<vector<int>>, int>> adj(k);
    for(int i = 0; i < k; i++) adj[i].s = k-1-i;
    while(k--) {
        int n; cin >> n;
        adj[k].f = vector<vector<int>>(n);
        for(int i = 0; i+1 < n; i++) {
            int u, v; cin >> u >> v;
            adj[k].f[--u].push_back(--v);
            adj[k].f[v].push_back(u);
        }
    }

    sort(adj.begin(), adj.end(), [](auto &a, auto &b) {return sz(a.f) > sz(b.f);});
    //main
    vector<array<int, 4>> ans;
    int s = 0;
    if(sz(adj[0].f) > 1) {
        //pick anyone whos a parent of a leaf
        for(auto &v : adj[0].f) if(sz(v) == 1) {
            s = v[0]; break;
        }
    }

    for(int t = 1; t < sz(adj); t++) {
        for(int i = 0; i < sz(adj[t].f); i++) {
            if(sz(adj[t].f[i]) != 1 || sz(adj[t].f) == 2) {
                ans.push_back({adj[0].s+1, s+1, adj[t].s+1, i+1});
                break;
            }
        }
    }

    for(auto &v : ans) {
        for(auto &i : v) cout << i << " ";
        cout << "\n";
    }
}

//king of the sun o_O
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