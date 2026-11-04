#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

const ll MOD = 1e9+7;
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
    vector<ll> a(n); for(ll &i : a) cin >> i;
    vector<pair<int, int>> ivl(n);
    for(int i = 0; i < n; i++) ivl[i] = {i, i};

    //figure out ivls
    vector<pair<int, int>> adj(n, {-1, -1});
    queue<int> bfs; int le = n;
    for(int i = 0; i < n; i++) if(a[i]==1) bfs.push(i);
    int lst;
    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop(); le--;
        if(0 < ivl[x].first) {
            int y = ivl[x].first-1;
            ivl[y].second = ivl[x].second;
            adj[y].second = x;
            if(ll(y-ivl[y].first+1)*(ivl[y].second-y+1) == a[y]) bfs.push(y);
        }
        if(ivl[x].second < n-1) {
            int y = ivl[x].second+1;
            ivl[y].first = ivl[x].first;
            adj[y].first = x;
            if(ll(y-ivl[y].first+1)*(ivl[y].second-y+1) == a[y]) bfs.push(y);
        }
        lst = x;
    }

    if(le) {cout << 0; return;}
    
    vector<mi> fac(n+1, 1), ifac(n+1, 1);
    for(int i = 2; i <= n; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = (-MOD/i)*ifac[MOD%i];
    }
    for(int i = 1; i <= n; i++) ifac[i]*=ifac[i-1];

    auto dfs = [&](auto&& self, int x) -> mi {
        auto& [l, r] = ivl[x];
        if(ll(r-x+1)*(x-l+1) != a[x]) return 0;
        mi ans = fac[r-l]*ifac[r-x]*ifac[x-l];
        if(adj[x].first != -1) ans *= self(self, adj[x].first);
        if(adj[x].second != -1) ans *= self(self, adj[x].second);
        return ans;
    };

    assert(ivl[lst].first == 0 && ivl[lst].second==n-1);
    cout << dfs(dfs, lst);
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