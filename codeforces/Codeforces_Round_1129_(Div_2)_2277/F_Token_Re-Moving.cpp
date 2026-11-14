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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    vector<mi> a(n); for(auto &i : a) cin >> i.v;
    vector<int> p(n); for(auto &i : p) cin >> i, i--;
    vector<int> ip(n); for(int i = 0; i < n; i++) ip[p[i]] = i;

    vector<int> par(n, -1);
    vector<int> mn = ip;
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        int z = min(mn[x], mn[y]);
        mn[x] = z, mn[y] = z;
        return 1;
    };


    vector<int> dfspar(n, -1);
    vector<mi> s = a; mi tot = accumulate(all(a), (mi)0);
    auto dfs = [&](auto &&self, int x) -> void {
        for(int y : adj[x]) {
            if(y == dfspar[x]) continue;
            dfspar[y] = x;
            self(self, y);
            s[x] += s[y];
        }
    };
    dfs(dfs, 0);

    vector<mi> ans(n);
    vector<vector<pair<int, mi>>> adj2(n);
    for(int i = n-1; i >= 0; i--) {
        //attach it to everything bigger.
        for(int y : adj[p[i]]) {
            if(ip[y] > i) {
                int z = mn[find(y)];
                adj2[p[i]].push_back({p[z], y==dfspar[p[i]] ? s[p[i]] : tot-s[y]});
                unite(p[i], y);
            }
        }
    }

    mi cur = tot;
    auto dfs2 = [&](auto&& self, int x) -> void {
        ans[x] = cur;
        for(auto [y, w] : adj2[x]) {
            cur += w;
            self(self, y);
            cur -= w;
        }
    };
    dfs2(dfs2, p[0]);

    for(auto &i : ans) cout << i << " ";
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