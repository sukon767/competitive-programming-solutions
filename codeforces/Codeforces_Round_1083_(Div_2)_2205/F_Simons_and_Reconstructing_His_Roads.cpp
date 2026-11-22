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
    vector<vector<ll>> w(n-1, vector<ll>(m)), v(n, vector<ll>(m-1));
    for(auto &i : w) for(auto &j : i) cin >> j;
    for(auto &i : v) for(auto &j : i) cin >> j;
    int N = (n+1)*(m+1);
    vector<int> par(N, -1);
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    };

    auto co = [&](int r, int c) {return (m+1)*r + c;};
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            char p; cin >> p;
            if(p == '0') unite(co(i+1, j), co(i+1, j+1));
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m-1; j++) {
            char q; cin >> q;
            if(q == '0') unite(co(i, j+1), co(i+1, j+1));
        }
    }

    vector<ll> sum((n+1)*(m+1));
    vector<bool> bad((n+1)*(m+1));

    for(int i = 0; i < (n+1)*(m+1); i++) {
        int r = i/(m+1), c = i%(m+1);
        if(r == 0 || r == n || c == 0 || c == m) {
            bad[find(i)] = 1;
            continue;
        }
        r--, c--;
        sum[find(i)] += w[r][c] + v[r][c] - w[r][c+1] - v[r+1][c];
    }

    ll ans = 0;
    for(int i = 0; i < (n+1)*(m+1); i++) if(!bad[i] && sum[i] > 0) ans += sum[i];

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