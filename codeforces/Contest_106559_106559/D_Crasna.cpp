#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

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

const mi i2 = mi(1)/2;

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    if(n==1) {cout << 1; return;}
    int cnt = 0; for(auto&v : adj) cnt += sz(v)==1;
    if(cnt==2) {
        mi ans = 2; for(int i = 1; i <= n-2; i++) ans *= i;
        cout << ans;
        return;
    }
    vector<vector<mi>> dp(n, vector<mi>(3));
    vector<bool> vis(n);
    auto dfs = [&](auto&& self, int x) -> void {
        vis[x] = 1;
        if(sz(adj[x])==1) {dp[x][0] = 1; return;}
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            dp[x][0] += dp[y][0];
            dp[x][1] += dp[y][1]+dp[y][0];
            dp[x][2] += dp[y][2];
            dp[x][2] -= (dp[y][1]+dp[y][0])*dp[y][0];
        }
        dp[x][2] += dp[x][1]*dp[x][0];
    };
    for(int i = 0; i < n; i++) {
        if(sz(adj[i])>1) {
            dfs(dfs, i);
            mi dc2 = dp[i][0]*(dp[i][0]-1);
            mi ans = dc2*(n-2) - (2*dp[i][2]-dc2);
            for(int j = 1; j <= n-3; j++) ans *= j;
            cout << ans;
            return;
        }
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