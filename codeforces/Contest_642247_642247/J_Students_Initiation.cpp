#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

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
        for (int& i = ptr[v]; i < (int)adj[v].size(); i++) {
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

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edge(m);
    for(auto &p : edge) {cin >> p.f >> p.s; p.f--, p.s--;}
    int lo = 0, hi = n;
    while(lo < hi) {
        int mid = (lo+hi)>>1;
        Dinic flw(n+m+2);
        for(int i = 0; i < n; i++) {
            flw.addEdge(n+m, i, mid);
        }
        for(int i = n; i < n+m; i++) {
            flw.addEdge(i, n+m+1, 1);
        }
        for(int i = 0; i < m; i++) {
            flw.addEdge(edge[i].f, n+i, 1);
            flw.addEdge(edge[i].s, n+i, 1);
        }
        ll x = flw.calc(n+m, n+m+1);
        if(x == m) hi = mid;
        else lo = mid+1;
    }

    Dinic flw(n+m+2);
    for(int i = 0; i < n; i++) {
        flw.addEdge(n+m, i, lo);
    }
    for(int i = n; i < n+m; i++) {
        flw.addEdge(i, n+m+1, 1);
    }
    for(int i = 0; i < m; i++) {
        flw.addEdge(edge[i].f, n+i, 1);
        flw.addEdge(edge[i].s, n+i, 1);
    }
    flw.calc(n+m, n+m+1);

    vector<pair<int, int>> ans = edge;
    for(int i = 0; i < m; i++) {
        auto& [u, v] = edge[i];
        for(auto &e : flw.adj[v]) {
            if(e.to == n+i) {
                if(e.flow()) ans[i] = {v, u};
                break;
            }
        }
    }

    cout << lo << "\n";
    for(auto &p : ans) cout << (p.f+1) << " " << (p.s+1) << "\n";
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