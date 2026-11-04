#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, z; cin >> n >> z;
    vector<int> x(n); for(int& i : x) cin >> i;
    int q; cin >> q;
    vector<vector<pair<int, int>>> que(n);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        que[--l].push_back({--r, i});
    }

    int L = 20;
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(L));
    auto par2 = par;
    
    vector<int> d(n+1);
    for(int i = n-1; i >= 0; i--) {
        auto it = upper_bound(all(x), x[i]+z);
        par[i][0] = {distance(x.begin(), it), 1};
        d[i] = par[i][0].f==n?1:d[par[i][0].f]+1;
    }

    for(int j = 1; j < L; j++) {
        for(int i = 0; i < n; i++) {
            par[i][j] = par[i][j-1].f==n?par[i][j-1]:pair<int, int>{par[par[i][j-1].f][j-1].f, par[i][j-1].s + par[par[i][j-1].f][j-1].s};
        }
    }
    
    auto findkth = [&](int x, int k, vector<vector<pair<int, int>>> &par) {
        int r = 0;
        for(int b = 0; b < L; b++) {
            if(k>>b&1) {
                r += par[x][b].s;
                x = par[x][b].f;
            }
            if(x==n) break;
        }
        return pair<int, int>{x, r};
    };
    
    auto lca = [&](int x, int y) {
        int r = 0;
        if(d[x] < d[y]) swap(x, y);
        auto p = findkth(x, d[x]-d[y], par);
        x = p.f; r += p.s;
        if(x==y) return pair<int, int>{x, r};
        for(int b = L-1; b >= 0; b--) {
            if(par[x][b].f != par[y][b].f) {
                r += par[x][b].s + par[y][b].s;
                x = par[x][b].f, y = par[y][b].f;
            }
        }
        return pair<int, int>{par[x][0].f, r + 2*par[x][0].s};
    };
    
    auto bs = [&](int x, int y, vector<vector<pair<int, int>>> &par) {
        int r = 0;
        for(int b = L-1; b >= 0; b--) {
            if(par[x][b].f <= y) {
                r += par[x][b].s;
                x = par[x][b].f;
            }
        }
        return pair<int, int>{x, r};
    };

    // for(int i = 0; i < n; i++) {
    //     cout << i << " " << par[i][0].f << " " << d[i] << endl;
    // }
    for(int i = n-1; i >= 0; i--) {
        par2[i][0] = lca(i, i+1);
        // cout << i << " " << par2[i][0].f << " " << par2[i][0].s << " " << d[i] << endl;
    }

    swap(par, par2);
    for(int j = 1; j < L; j++) {
        for(int i = 0; i < n; i++) {
            par[i][j] = par[i][j-1].f==n?par[i][j-1]:pair<int, int>{par[par[i][j-1].f][j-1].f, par[i][j-1].s + par[par[i][j-1].f][j-1].s};
        }
    }
    swap(par, par2);

    vector<int> ans(q);
    for(int l = 0; l < n; l++) {
        // int r = 5, ind = 0;
        for(auto& [r, ind] : que[l]) {
            if(l==r) {ans[ind] = 1; continue;}
            auto [l2, c] = bs(l, r-1, par2);
            auto [ig1, c1] = bs(l2, r, par);
            // cout << l2 << " " << ig1 << " " << c1 << endl;
            auto [ig2, c2] = bs(l2+1, r, par);
            ans[ind] = c+c1+c2+2 - (ig1==ig2);
        }
    }

    for(int x : ans) cout << x << "\n";
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