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

//sukon always reads the entire problem statement.
void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        adj[--x].push_back(i);
    }

    int L = 20;
    vector<pair<mi, mi>> dp(n, {1, 0}), dpd(n); //including, not including.
    vector<vector<pair<int, mi>>> par(n, vector<pair<int, mi>>(L, {-1, 0}));
    vector<int> d(n);

    for(int x = n-1; x >= 0; x--) {
        for(int y : adj[x]) {
            dp[x].f *= 1+dp[y].f;
            dp[x].s += dp[y].f+dp[y].s;
        }
    }

    for(int x = 0; x < n; x++) {
        vector<pair<mi, mi>> pre;
        for(int y : adj[x]) {
            d[y] = d[x]+1;
            par[y][0] = {x, dp[x].s-dp[y].f-dp[y].s};
            pre.push_back({1+dp[y].f, dp[y].f+dp[y].s});
        }
        auto suf = pre; int w = sz(adj[x]);
        for(int i = 1; i < w; i++) pre[i] = {pre[i].f*pre[i-1].f, pre[i].s+pre[i-1].s};
        for(int i = w-2; i >= 0; i--) suf[i] = {suf[i].f*suf[i+1].f, suf[i].s+suf[i+1].s};
        for(int i = 0; i < w; i++) {
            int y = adj[x][i];
            dpd[y].f = (i ? pre[i-1].f : 1) * (i+1 < w ? suf[i+1].f : 1) * (1+dpd[x].f);
            dpd[y].s = (i ? pre[i-1].s : 0) + (i+1 < w ? suf[i+1].s : 0) + (dpd[x].f+dpd[x].s);
        }
    }

    for(int j = 1; j < L; j++) {
        for(int i = 0; i < n; i++) {
            if(par[i][j-1].f == -1) {
                par[i][j] = {-1, par[i][j-1].s};
            } else {
                int x = par[i][j-1].f;
                par[i][j] = {par[x][j-1].f, par[i][j-1].s + par[x][j-1].s};
            }
        }
    }

    auto kth = [&](int x, int k) {
        pair<int, mi> ans = {x, 0};
        for(int i = L-1; i >= 0; i--) {
            if(k>>i&1) ans = {par[ans.f][i].f, par[ans.f][i].s + ans.s};
            if(ans.f == -1) break;
        }
        return ans;
    };

    auto lca = [&](int x, int y) {
        if(d[x] < d[y]) swap(x, y);
        mi ans = dp[x].s + dp[y].s;
        auto [nx, nans] = kth(x, d[x]-d[y]);
        x = nx; ans += nans;
        if(x == y) {
            //handle it differnetly
            return ans - dp[y].s + (dpd[y].f+dpd[y].s);
        }
        for(int i = L-1; i >= 0; i--) {
            if(par[x][i].f != par[y][i].f) {
                ans += par[x][i].s + par[y][i].s;
                x = par[x][i].f, y = par[y][i].f;
            }
        }
        int z = par[x][0].f;
        return (ans + par[x][0].s + par[y][0].s - dp[z].s + (dpd[z].f + dpd[z].s));
    };

    for(int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        mi z = (dp[0].f+dp[0].s) - lca(--u, --v);
        cout << z << "\n";
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
        // if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */