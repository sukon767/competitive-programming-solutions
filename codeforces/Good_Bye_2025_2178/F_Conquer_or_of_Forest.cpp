#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

ll MOD = 998244353;
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

vector<vector<int>> tadj, adj;
vector<bool> visited;

int dfs(int x, int par) {
    int c = 1;
    visited[x] = true;
    for(int y : adj[x]) 
        if(!visited[y])
            c += dfs(y, x);
            
    if(x && c%2) {tadj[x].push_back(par); tadj[par].push_back(x);}
    return c;
}

int dfs2(int x) {
    int c = 1;
    visited[x] = true;
    for(int y : tadj[x]) 
        if(!visited[y]) {
            c += dfs2(y);
        }
    return c;
}

void solve() {
    int n; cin >> n;
    adj = tadj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }
    
    dfs(0, -1);
    vector<int> vals;
    visited = vector<bool>(n);

    int cur = 0;

    while(cur < n) {
        if(!visited[cur]) 
            vals.push_back(dfs2(cur));
        cur++;
    }

    if(vals.size() == 1) {cout << 1; return;}

    mi ans = 0;
    for(int i = 1; i < vals.size(); i++)
        ans += inv(vals[i]);

    for(int i = 0; i < vals.size(); i++) {
        if(i)   ans *= vals[i];
        ans *= vals[i];
    }

    for(int i = 1; i <= int(vals.size())-2; i++) ans *= i;

    cout << ans;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}