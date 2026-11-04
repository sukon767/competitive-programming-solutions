#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

const ll MOD = 998244353;
struct mi {
ll v;
explicit operator ll() const { return v; }
mi() { v = 0; }
mi(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }
bool operator<(const mi& other) const {
return v < other.v;
}
friend std::ostream& operator<<(std::ostream& os, const mi& m) {
  os << m.v;
  return os;
}
};
mi &operator+=(mi &a, mi b) {
if ((a.v += b.v) >= MOD) a.v -= MOD;
return a;
}
mi &operator-=(mi &a, mi b) {
if ((a.v -= b.v) < 0) a.v += MOD;
return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(a.v * ll(b.v)); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, ll p) {
assert(p >= 0);
return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
assert(a.v != 0);
return pow(a, MOD-2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
mi& operator/=(mi& a, mi b) { return a = a/b; }
bool operator==(mi a, mi b) {return a.v == b.v;}
bool operator!=(mi a, mi b) {return a.v != b.v;}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> adj(n), kid(n);
    for(int i = 0; i+1 < n; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<int> par(n, -1);
    vector<int> ord;
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = 1;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            par[y] = x; kid[x].push_back(y);
            self(self, y);
        }
        ord.push_back(x);
    };
    dfs(dfs, 0);

    vector<vector<mi>> dp(n, vector<mi>(n));
    vector<vector<mi>> same(n, vector<mi>(n));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j <= i; j++) {
            int u = ord[i], v = ord[j];

            for(int z : kid[v]) same[u][v]+=same[u][z];
            if(u!=v) for(int y : kid[u]) same[v][u]+=same[v][y];
            //currently dp[u][v] is just the children.
            //currently same[x][y] is x, proper subtree of y, so here include y
            
            for(int y : kid[u]) for(int z : kid[v]) dp[u][v] += dp[y][z];
            
            // cout << u+1 << " " << v+1 << " " << dp[u][v] << " " << same[u][v] << " " << same[v][u] << endl;
            mi cuv = dp[u][v]; //sum of children answers
            dp[u][v] += same[u][v]+same[v][u]; //choose u, subtree of v that has same as u.
            
            if(s[u] == s[v]) {
                dp[u][v]+=cuv+1;
                same[u][v]+=cuv+1;
                if(u!=v) same[v][u]+=cuv+1;
            }
            dp[v][u] = dp[u][v];
        }

    for(int i = 0; i < n; i++) cout << dp[i][i] << " ";
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */