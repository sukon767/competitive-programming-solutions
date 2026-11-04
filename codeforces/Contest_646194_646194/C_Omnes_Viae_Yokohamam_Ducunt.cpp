#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> p(n); for(ll& i : p) cin >> i;
    vector<vector<pair<int, ll>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, q; cin >> u >> v >> q;
        adj[--u].push_back({--v, q});
        adj[v].push_back({u, q});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    vector<ll> d(n, LLONG_MAX>>1);
    pq.push({0, 0});

    while(sz(pq)) {
        ll ds = pq.top().f, x = pq.top().s; pq.pop();
        if(d[x] < ds) continue;
        d[x] = ds;
        for(auto & [y, w] : adj[x]) {
            pq.push({w+ds, y});
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += d[i]*p[i];
    cout << ans;
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */