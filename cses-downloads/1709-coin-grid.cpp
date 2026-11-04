#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }    // if you need flows
    };
    vector<int> lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, (int)adj[b].size(), c, c});
        adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < adj[v].size(); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0;
        q[0] = s;
        for (int L = 0; L < 31; L++)
            do {  // 'int L=30' maybe faster for random data
                lvl = ptr = vector<int>(q.size());
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);
        return flow;
    }
    bool minCutSourceSide(int a) { return lvl[a] != 0; }
};
void solve() {
    int n; cin >> n;
    Dinic d(2*n + 2);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            char xx; cin >> xx;
            if(xx != '.') d.addEdge(i, j+n, INT_MAX);
        }
    for(int i = 0; i < n; i++) {
        d.addEdge(2*n, i, 1); d.addEdge(i+n, 2*n+1, 1);
    }
    ll ans = d.calc(2*n, 2*n+1);
    cout << ans;
    int cnt = 0;
    for(int i = 0; i < d.adj.size(); i++) {
        for(auto cc : d.adj[i]) {
            if(d.minCutSourceSide(i) && !d.minCutSourceSide(cc.to)) {
                if(i == 2*n) {
                    cout << "\n" << 1 << " " << (cc.to+1);
                } else {
                    if(cc.to == 2*n+1)
                        cout << "\n" << 2 << " " << (i+1-n);
                }
            }
        }
    }
    // cout << endl;
    // for(auto cc : d.adj[6])
    // cout << cc.to << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}
