#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<vector<int>> adj;
//init disc to -1, st should be empty, everything else length n
vector<int> disc, low, st, id;
vector<bool> inStack;
int timer = 0, col = 0;

void dfs(int u) {
    disc[u] = low[u] = timer++;
    st.push_back(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        while (true) {
            int v = st.back();
            st.pop_back();
            inStack[v] = false;
            id[v] = col;
            if (v == u) break;
        }
        col++;
    }
}
//paste this into solve()
// adj.resize(n, {}); disc.resize(n, -1); low.resize(n); id.resize(n); inStack.resize(n);
//
// for(int i = 0; i < n; i++) {
//     if(disc[i] == -1)
//         dfs(i);
// }

void solve() {
    int n; cin >> n;
    adj.resize(n, {}); disc.resize(n, -1); low.resize(n); id.resize(n); inStack.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x; if(x) adj[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++) {
        if(disc[i] == -1)
            dfs(i);
    }

    vector<vector<int>> scc(*max_element(id.begin(), id.end())+1);
    for(int i = 0; i < n; i++) scc[id[i]].push_back(i);
    int S = sz(scc);
    
    vector<vector<int>> adj2(S);
    for(int i = 0; i < n; i++) {
        for(int j : adj[i]) {
            if(id[i]!=id[j]) adj2[id[i]].push_back(id[j]);
        }
    }
    for(auto& v : adj2) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
    
    int te = 0;
    vector<int> in(S);
    for(auto& v : adj2) {
        for(int j : v) {
            in[j]++;
            te++;
        }
    }
    // cout << "asdf" << endl;
    
    vector<int> topo;
    queue<int> bfs;
    for(int i = 0; i < S; i++) if(!in[i]) bfs.push(i);
    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop(); topo.push_back(x);
        for(int j : adj2[x]) {in[j]--; if(!in[j]) bfs.push(j);}
    }
    assert(sz(topo)==S);
    vector<int> inv(S);
    for(int i = 0; i < S; i++) inv[topo[i]]=i;

    vector<vector<string>> ans(2*S, vector<string>(4));
    for(int i = 0; i < 2*S; i++) {
        if(i%2==0) {
            for(auto&s : ans[i]) s.resize(3*(te+1), '.');
            for(int j = 0; j < sz(scc[topo[i/2]]); j++) ans[i][j/3][j%3]='1'+scc[topo[i/2]][j];
        } else {
            for(auto&s : ans[i]) s.resize(3*(te+1), '#');
        }
    }

    for(int i = 0; i < S; i++) {
        for(int j : adj2[i]) {
            for(int k = inv[i]; k < inv[j]; k++) {
                if(k>inv[i]) {
                    for(int r = 0; r < 3; r++) {
                        for(int s = 0; s < 3; s++) {
                            if(r!=1 || s!=1) ans[2*k][r][3*te+s]='#';
                        }
                    }
                }
                ans[2*k+1][1][3*te+1]='.';
            }
            te--;
        }
    }

    assert(sz(ans) && sz(ans[0]) && sz(ans[0][0]));
    cout << sz(ans[0][0]) << " " << sz(ans[0]) << " " << sz(ans) << "\n";
    for(auto&v : ans) {
        for(auto&s : v) cout << s << "\n";
        cout << "\n";
    }
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