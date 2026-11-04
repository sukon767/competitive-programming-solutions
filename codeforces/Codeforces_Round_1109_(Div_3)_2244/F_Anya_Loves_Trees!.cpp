#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//ASDFHJKLASDFHJKLASDFHJKL

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++) {
        int u; cin >> u;
        adj[--u].push_back(i);
    }
    vector<pair<int, int>> bd(n);
    for(int i = 0; i < n; i++) {
        int ai; cin >> ai;
        if(ai) bd[i] = {ai, ai};
    }

    auto dfs = [&](auto&&self, int x) -> bool {
        vector<pair<int, int>> c;
        for(int y : adj[x]) {
            if(!self(self, y)) return false;
            c.push_back(bd[y]);
        }
        if(!sz(c)) return true;
        int j = distance(c.begin(), min_element(all(c)));
        rotate(c.begin(), c.begin() + j, c.end());
        for(int i = 0; i+1 < sz(c); i++) if(c[i].s+1 != c[i+1].f) return false;
        bd[x] = {c[0].f, c.back().s};
        return true;
    };

    if(dfs(dfs, 0)) cout << "YES";
    else cout << "NO";
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