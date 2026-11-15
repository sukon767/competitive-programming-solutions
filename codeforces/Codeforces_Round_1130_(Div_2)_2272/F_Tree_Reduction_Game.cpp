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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    auto check = [](array<int, 3> &v) {
        int sum = accumulate(all(v), 0);
        if(sum) {
            if(v[1]) return 2;
            else if(sum&1) return 1;
        }
        return 0;
    };

    vector<int> dpu(n), dpd(n);
    vector<array<int, 3>> kid(n);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(int y : adj[x]) {
            if(y == p) continue;
            self(self, y, x);
            kid[x][dpu[y]]++;
        }
        dpu[x] = check(kid[x]);
    };
    dfs(dfs, 0, -1);

    auto dfs2 = [&](auto &&self, int x, int p) -> void {
        for(int y : adj[x]) {
            if(y == p) continue;
            auto v = kid[x];
            v[dpu[y]]--;
            if(x) v[dpd[x]]++;

            dpd[y] = check(v);
            self(self, y, x);
        }
    };
    dfs2(dfs2, 0, -1);

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        //kids with dpd
        auto v = kid[i];
        if(i) v[dpd[i]]++;
        if(!check(v)) ans.push_back(i+1);
    }
    if(ans.empty()) cout << "Alice";
    else {
        cout << "Bob\n" << sz(ans) << "\n";
        for(int x : ans) cout << x << " ";
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