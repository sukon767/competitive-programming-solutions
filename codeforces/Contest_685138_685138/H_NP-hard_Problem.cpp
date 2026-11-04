#include<bits/stdc++.h>
 
using namespace std;

struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};
 
using ll = long long;
using ld = long double;
const int N = 2e5;
vector<int> g[N];
bool color[N];
bool vis[N];
int n;
void dfs(int s, bool b){
    vis[s] = 1;
    color[s] = b;
    for(int i: g[s]) if(!vis[i])
        dfs(i,!b);
}
vector<int> findS(){
    fill(vis,vis+n,0);
    for(int i = 0; i<n; i++) if(g[i].size() && !vis[i])
        dfs(i, 1);
    vector<int> a,b;
    for(int i = 0; i<n; i++) if(g[i].size()){
        if(color[i])
            a.push_back(i);
        else b.push_back(i);
    }
    return a.size() < b.size() ? a:b;
}
bool first;
void solve() {
    int m; cin >> n >> m;
    if(first){
        vector<int> c(n);
        for(int& i: c) cin >> i;
        for(int i = 0; i<n; i++) g[i].clear();
        while(m--){
            int a,b; cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
        }
        vector<int> cur = findS();
        cout << cur.size() << "\n";
        for(int i: cur) cout << c[i] << " ";
    }else{
        int k; cin >> k;
        vector<int> arr(k);
        for(int& i: arr) cin >> i;
        for(int i = 0; i<n; i++) g[i].clear();
        while(m--){
            int a,b; cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
        }
        vector<int> vals = findS();
        vector<bool> white(n);
        for(int i: vals) white[i] = 1;
        vector<vector<int>> color(n);
        for(int i = 0; i<n; i++) if(g[i].size() == 0) color[i] = {1};
        for(int i = 0; i<k; i++) color[vals[i]] = {arr[i]};
        for(int i = 0; i<n; i++) if(g[i].size() && !white[i]){
            set<int> can{1,2,3};
            for(int j: g[i]) if(white[j])
                can.erase(color[j][0]);
            color[i] = vector<int>(can.begin(),can.end());
        }
        TwoSatSolver solver(n);
        for(int i = 0; i<n; i++) if(!white[i]){
            for(int j: g[i]) if(j > i && !white[j]){
                for(int k = 0; k<2; k++) for(int l = 0; l<2; l++) if(k == color[i].size() || l == color[j].size() || color[i][k] == color[j][l]){
                    solver.add_disjunction(i, k == 1, j, l == 1);
                }
            }
        }
        assert(solver.solve_2SAT());
        vector<bool> ass = solver.assignment;
        for(int i = 0; i<n; i++) if(color[i].size() == 1)
            cout << color[i][0] << " ";
        else cout << color[i][ass[i]] << " ";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    first = s == "first";
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}