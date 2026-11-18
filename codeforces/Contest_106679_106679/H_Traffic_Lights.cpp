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
    vector<int> v(n); for(auto &i : v) cin >> i;
    for(int i = n-1; i > 0; i--) v[i] ^= v[i-1];

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

    vector<bool> free(n);
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--;
        if(r != n) unite(l, r);
        else free[l] = 1;
    }

    vector<vector<int>> cc(n);
    for(int i = 0; i < n; i++) cc[find(i)].push_back(i);

    for(auto &c : cc) {
        if(c.empty()) continue;
        int bad = 0, ex = 0;
        for(auto &i : c) {
            if(free[i]) ex++;
            else if(v[i]) bad++;
        }
        if((bad&1) && !ex) {
            cout << "NO"; return;
        }
    }

    cout << "YES";
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