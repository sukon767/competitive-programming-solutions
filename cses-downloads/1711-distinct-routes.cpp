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
int n, cnt = 0;
vector<int> ans;
vector<vector<pair<int, bool>>> rec;
bool dfs(int x) {
    cnt++;
    ans.push_back(x);
    if(x == n-1) { return true;}
    for(auto &y : rec[x]) {
        if(y.second) {y.second = false; dfs(y.first); return true;};
    }
    return false;
}
void solve() {
    int m; cin >> n >> m;
    Dinic d(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        d.addEdge(--a, --b, 1);
    }
    cout << d.calc(0, n-1);
    rec = vector<vector<pair<int, bool>>> (n);
    for(int i = 0; i < n; i++)
        for(auto bb : d.adj[i]) {
            if(bb.flow()) {
                rec[i].push_back({bb.to, true});
                // cout << i <<  " " << bb.to << endl;
            }
        }
    ans = vector<int>();
    cnt = 0;
    while(dfs(0)) {
        cout << "\n" << cnt << "\n";
        for(int i = 0; i < ans.size(); i++) {
            if(i) cout << " "; cout << ans[i]+1;
        }
        ans = vector<int>();
        cnt = 0;
    }
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
