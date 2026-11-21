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
    int n, m; cin >> n >> m;
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
    vector<vector<int>> adj(n);
    while(m--) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
        unite(u, v);
    }

    int on = 0;
    vector<bool> vis(n);
    vector<int> label(n), ilabel(n);
    auto dfs = [&](auto &&self, int x) -> void {
        vis[x] = 1;
        label[x] = on;
        ilabel[on] = x;
        on++;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
        }
    };
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    
    auto check = [&](int l, int r) {
        int lo = l, hi = r;
        while(lo < hi) {
            int mid = (lo+hi)>>1;
            int k = n - (r-mid);
            cout << "? 1 " << k;
            for(int i = 0; i < n; i++) {
                if(i <= mid || i > r) cout << " " << ilabel[i]+1;
            }
            cout << endl;
            int ret; cin >> ret;
            if(ret) lo = mid+1;
            else hi = mid;
        }
        return ilabel[lo];
    };

    int x = check(0, n-1);
    on = 0;
    fill(all(vis), 0);
    dfs(dfs, x);
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    int y = check(-par[find(x)], n-1);

    cout << "? 2 " << x+1 << " " << y+1 << endl;
    int ret; cin >> ret;
    if(ret) {
        cout << "! " << x+1 << " " << y+1 << endl;
        return;
    }

    if(-par[find(x)] > -par[find(y)]) swap(x, y);
    
    on = 0;
    fill(all(vis), 0);
    dfs(dfs, x);
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);
    int z = check(1, -par[find(x)]-1);
    
    cout << "! " << y+1 << " " << z+1 << endl;
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