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
    vector<int> par(n, -1);
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    };
    vector<array<ll, 4>> edge;
    for(int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        edge.push_back({w, --u, --v, i});
    }
    sort(all(edge));
    vector<bool> ans(m);
    int i = 0;
    while(i < sz(edge)) {
        int st = i;
        while(i < sz(edge) && edge[i][0] == edge[st][0]) {
            if(find(edge[i][1]) != find(edge[i][2])) ans[edge[i][3]] = 1;
            i++;
        }
        i = st;
        while(i < sz(edge) && edge[i][0] == edge[st][0]) {
            unite(edge[i][1], edge[i][2]);
            i++;
        }
    }
    for(bool b : ans) cout << (b ? "YES\n" : "NO\n");
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
