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
    int x, y, z; cin >> x >> y >> z;
    vector<vector<string>> g(z, vector<string>(x));
    vector<bool> gas(x*y*z);
    for(int i = 0; i < z; i++) {
        for(int j = 0; j < x; j++) {
            cin >> g[i][j];
            for(int k = 0; k < y; k++) {
                if(g[i][j][k] == '.') gas[j + x*k + x*y*i] = 1;
            }
        }
    }

    vector<vector<int>> adj(x*y*z);
    for(int i = 0; i < x*y*z; i++) {
        if(!gas[i]) continue;
        int X = i%x, Y = (i/x)%y, Z = i/x/y;
        vector<vector<int>> cont;
        if(X) cont.push_back({X-1, Y, Z});
        if(Y) cont.push_back({X, Y-1, Z});
        if(Z) cont.push_back({X, Y, Z-1});
        if(X+1 < x) cont.push_back({X+1, Y, Z});
        if(Y+1 < y) cont.push_back({X, Y+1, Z});
        if(Z+1 < z) cont.push_back({X, Y, Z+1});
        for(auto& v : cont) {
            int j = v[0] + x*v[1] + x*y*v[2];
            if(gas[j]) adj[i].push_back(j);
        }
    }

    vector<int> ccs(1);
    vector<int> col(x*y*z);
    auto dfs = [&](auto&& self, int i) -> void {
        col[i] = sz(ccs)-1;
        ccs.back()++;
        for(int j : adj[i]) {
            if(col[j]) continue;
            self(self, j);            
        }
    };
    
    for(int i = 0; i < x*y*z; i++) {
        if(!col[i] && gas[i]) {
            ccs.push_back(0);
            dfs(dfs, i);
        }
    }

    int ans = 0;
    for(int i = 0; i < x*y; i++) {
        vector<int> c;
        for(int j = 0; j < z; j++) {
            if(gas[i+x*y*j]) c.push_back(col[i+x*y*j]);
        }
        sort(all(c)); c.erase(unique(all(c)), c.end());
        int cur = 0;
        for(int x : c) cur += ccs[x];
        ans = max(ans, cur);
    }

    cout << ans;
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