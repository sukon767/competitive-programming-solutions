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

    string x, y; cin >> x >> y;
    vector<int> par(n, -1), d(n, 0);
    auto dfs = [&](auto&& self, int x, int p) -> void {
        par[x] = p;
        for(int y : adj[x]) {
            if(y == p) continue;
            d[y] = d[x]+1;
            self(self, y, x);
        }
    };
    dfs(dfs, 0, -1);

    pair<int, int> bst = {0, 0};
    for(int i = 0; i < n; i++) {
        bst = max(bst, {d[i], i});
    }
    string s, t;
    while(bst.s != -1) {
        s += x[bst.s];
        t += y[bst.s];
        bst.s = par[bst.s];
    }
    reverse(all(s)); reverse(all(t));
    //t - s
    string sub = "";
    for(int i = 0; i < sz(s); i++) {
        if(t[i] < s[i]) {
            for(int j = i; j < sz(t); j++) {
                if(t[j] == '0') t[j] = '1';
                else {t[j] = '0'; break;}
            }
            sub += 1;
        } else sub += t[i]-s[i];
    }

    vector<int> fin(n);
    auto dfs2 = [&](auto&& self, int i, int p, int c) -> void {
        fin[i] = (x[i] - '0') + c + sub[d[i]];
        for(int j : adj[i]) {
            if(j == p) continue;
            self(self, j, i, fin[i]>>1);
        }
        fin[i] &= 1;
    };
    dfs2(dfs2, 0, -1, 0);

    for(int i = 0; i < n; i++) {
        if(fin[i] != (y[i]-'0')) {
            cout << -1; return;
        }
    }

    const ll MOD = 998244353;
    ll p2 = 1;
    ll ans = 0;
    for(int i = 0; i < sz(sub); i++) {
        if(sub[i]) ans = (ans+p2)%MOD;
        p2 = (p2*2)%MOD;
    }

    cout << ans;
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