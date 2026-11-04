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
    vector<vector<array<ll, 3>>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v, a, b; cin >> u >> v >> a >> b;
        adj[--u].push_back({--v, a, b});
        adj[v].push_back({u, b, a});
    }

    ll sum = 0;
    ll dis = 0;
    vector<ll> s(n, 1);
    auto dfs = [&](auto&&self, int x, int p) -> void {
        sum += dis;
        for(auto &v : adj[x]) {
            if(v[0] == p) continue;
            dis += v[1];
            self(self, v[0], x);
            dis -= v[1];
            s[x] += s[v[0]];
        }
    };
    dfs(dfs, 0, -1);

    vector<ll> ans(n);
    auto dfs2 = [&](auto&&self, int x, int p) -> void {
        ans[x] = sum;
        for(auto &v : adj[x]) {
            int y = v[0];
            if(y == p) continue;
            ll delta = (n-s[y])*v[2] - s[y]*v[1];
            sum += delta;
            self(self, y, x);
            sum -= delta;
        }
    };
    dfs2(dfs2, 0, -1);

    for(auto &x : ans) cout << x << " ";
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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