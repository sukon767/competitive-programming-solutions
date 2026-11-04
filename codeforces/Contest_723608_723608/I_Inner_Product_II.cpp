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
    vector<ll> a(n); for(auto &i : a) cin >> i;
    vector<pair<pair<int, int>, char>> edge;
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
    for(int i = 0; i+1 < n; i++) {
        int u, v; char c; cin >> u >> v >> c;
        u--, v--;
        if(c == '=') unite(u, v);
        else edge.push_back({{u, v}, c});
    }

    
    vector<ll> b(n, 0), in(n);
    vector<vector<int>> adj(n);
    for(auto p : edge) {
        auto [u, v] = p.f;
        u = find(u), v = find(v);
        if(p.s == '>') swap(u, v);
        adj[u].push_back(v);
        in[v]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //multisource
    for(int i = 0; i < n; i++) {
        if(find(i) == i && in[i]==0) {
            b[i] = 1;
            pq.push({1, i});
        }
    }

    while(!pq.empty()) {
        auto [dis, x] = pq.top(); pq.pop();
        if(dis != b[x]) continue;
        for(int y : adj[x]) {
            if(b[x]+1 > b[y]) {
                b[y] = b[x]+1;
                pq.push({b[y], y});
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        b[i] = b[find(i)];
        assert(b[i] != LLONG_MAX);
        ans += b[i]*a[i];
    }

    cout << ans << "\n";
    for(int x : b) cout << x << " ";
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