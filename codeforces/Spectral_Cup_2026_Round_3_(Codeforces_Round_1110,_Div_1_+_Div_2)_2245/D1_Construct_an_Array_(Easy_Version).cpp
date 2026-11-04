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
    int n, m; cin >> n >> m;

    // vector<int> par(n, -1);
    // function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    // function<bool(int, int)>    unite = [&](int x, int y) {
    //     x = find(x); y = find(y);
    //     if(x == y)  return 0;
    //     if(par[x] > par[y]) swap(x, y);
    //     par[x] += par[y];
    //     par[y] = x;
    //     return 1;
    // };

    vector<vector<int>> adj(n);
    vector<vector<int>> r;
    vector<int> vl(n), ans(n);

    for(int i = 0; i < m; i++) {
        int o, ix, jx; cin >> o >> ix >> jx;
        ix--; jx--;
        if(ix==jx) {
            vl[ix] = o;
        } else {
            r.push_back({o, ix, jx});
        }
    }

    // for(int i = 0; i < sz(r); i++) {
    //     if(vl[r[i][1]] == vl[r[i][2]]) {
    //         if(r[i][0] != vl[r[i][1]]) {cout << "NO"; return;}
    //         else continue;
    //     }

    //     if(r[i][0]==1) unite(r[i][1], r[i][2]);
    // }
    
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