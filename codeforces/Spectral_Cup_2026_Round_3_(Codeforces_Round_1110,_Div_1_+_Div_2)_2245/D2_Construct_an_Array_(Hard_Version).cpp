#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

struct two_sat {
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> comp, topological_order, answer; // comp[v]: ID of the SCC containing node v
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    // Topological sort
    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> r;
    vector<int> vl(n), ans(n);

    two_sat ts(n);

    for(int i = 0; i < m; i++) {
        int o, ix, jx; cin >> o >> ix >> jx;
        ix--; jx--;
        if(ix==jx) {
            vl[ix] = o;
        } else {
            r.push_back({o, ix, jx});
        }
        --o;
        ts.add_clause_or(ix, o, jx, o);
    }

    //2sat shit
    bool wrk = ts.satisfiable();
    if(!wrk) {
        cout << "NO"; return;
    }
    for(int i = 0; i < n; i++) {
        vl[i] = ts.answer[i]+1;
    }
    
    vector<int> deg(n);
    
    for(int i = 0; i < sz(r); i++) {
        if(vl[r[i][1]] == vl[r[i][2]]) {
            if(r[i][0] != vl[r[i][1]]) {cout << "NO"; return;}
            else continue;
        }

        if(r[i][0] == 2) {
            if(vl[r[i][1]] == 1) swap(r[i][1], r[i][2]);
            adj[r[i][2]].push_back(r[i][1]);
            deg[r[i][1]]++;
        } else {
            if(vl[r[i][1]] == 2) swap(r[i][1], r[i][2]);
            adj[r[i][2]].push_back(r[i][1]);
            deg[r[i][1]]++;
        }
    }


    queue<int> bfs;
    for(int i = 0; i < n; i++) {
        if(deg[i]==0) {
            ans[i] = 1;
            bfs.push(i);
        }
    }

    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop();
        for(int y : adj[x]) {
            ans[y] = max(ans[y], ans[x]+1);
            deg[y]--;
            if(deg[y]==0) bfs.push(y);
        }
    }

    ll s = accumulate(all(deg), 0LL);
    if(s) {
        cout << "NO";
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(vl[i]==2) ans[i] = -ans[i];
    }

    cout << "YES\n";
    for(int x : ans) cout << x << " ";
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