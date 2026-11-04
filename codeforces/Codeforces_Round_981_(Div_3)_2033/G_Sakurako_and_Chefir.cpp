#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

vector<vector<int>> par, adj, dia;
vector<bool> visited;
vector<int> d;

void dfs(int x) {
    // cout << x+1 << endl;
    visited[x] = true;
    dia[x] = {x, x, 0};

    vector<int> tl = {x};
    int b = 0, cur = x;
    while(par[cur].size() > b) {
        cur = par[cur][b]; b++;
        tl.push_back(cur);
    }

    vector<pair<int, int>> cont;
    for(int y : adj[x]) {
        if(visited[y]) continue;
        par[y] = tl;
        d[y] = d[x]+1;
        dfs(y);
        if(d[dia[y][0]] > d[dia[y][1]]) {cont.push_back({d[dia[y][0]] - d[x], dia[y][0]});}
        else {cont.push_back({d[dia[y][1]] - d[x], dia[y][1]});}
        
        if(dia[y][2] > dia[x][2]) dia[x] = dia[y];
    }

    //create dia
    sort(cont.begin(), cont.end()); reverse(cont.begin(), cont.end());
    if(!cont.size()) {dia[x] = {x, x, 0};}
    else if(cont.size() == 1) {
        if(cont[0].first >= dia[x][2])
            dia[x] = {cont[0].second, x, cont[0].first};
    }
    else if(cont[0].first + cont[1].first >= dia[x][2]) {
        dia[x][2] = cont[0].first + cont[1].first;
        dia[x][0] = cont[0].second, dia[x][1] = cont[1].second;
    }
}

int ak(int u, int k) {
    int ans = u;
    for(int i = 0; i < 31; i++) {
        if(k & (1 << i)) {
            if(par[ans].size() <= i) {return 0;}
            ans = par[ans][i];
        }
    }
    return ans;
}

int lca(int u, int v) {
    if(d[u] > d[v]) return lca(v, u);
    v = ak(v, d[v]-d[u]);
    if(u == v) return u;
    
    for(int i = 30; i >= 0; i--) {
        if(d[v] < (1 << i)) continue;
        if(par[u][i] != par[v][i]) {u = par[u][i], v = par[v][i];}
    }
    return par[u][0];
}

void solve() {
    int n; cin >> n;
    adj = vector<vector<int>>(n), par = vector<vector<int>>(n), dia = vector<vector<int>>(n, vector<int>(3));
    visited = vector<bool>(n);
    d = vector<int>(n);

    for(int i = 0; i < n-1; i++) {int u, v; cin >> u >> v; adj[--u].push_back(--v); adj[v].push_back(u);}
    dfs(0);

    // for(int i = 0; i < n; i++) {
    //     cout << i+1 << " " << dia[i][0]+1 << " " << dia[i][1]+1 << " " << dia[i][2] << endl;
    // }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int v, k; cin >> v >> k;
        int anc = ak(--v, k);

        // cout << endl << v+1 << " " << k << " " << anc+1 << endl;
        // cout << dia[anc][0]+1 << " " << dia[anc][1]+1 << endl;

        pair<int, int> cont = {dia[anc][0], dia[anc][1]}, lcas = {lca(v, cont.first), lca(v, cont.second)};
        cout << max(d[v]+d[cont.first]-2*d[lcas.first], d[v]+d[cont.second]-2*d[lcas.second]) << " ";
    }
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