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
    int n; cin >> n;
    vector<vector<ll>> M(n, vector<ll>(n));
    for(auto &v : M) for(auto& i : v) cin >> i;
    int m; cin >> m;
    vector<vector<ll>> d(n, vector<ll>(n));
    for(int t = 0; t < m; t++) {
        int i, j, x, y, k; cin >> i >> j >> x >> y >> k;
        i--, j--, x--, y--;
        //2d prefix sum
        if(i > x) swap(i, x);
        if(j > y) swap(j, y);
        d[i][j] += k;
        if(y+1 < n) d[i][y+1]-=k;
        if(x+1 < n) d[x+1][j]-=k;
        if(x+1 < n && y+1 < n) d[x+1][y+1]+=k;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i) d[i][j] += d[i-1][j];
            if(j) d[i][j] += d[i][j-1];
            if(i && j) d[i][j] -= d[i-1][j-1];

            if(i != j && M[i][j] != -1) M[i][j] += d[i][j];
        }
    }
    

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(M[i][k] == -1 || M[k][j] == -1) continue;
                ll sum = M[i][k] + M[k][j];
                M[i][j] = ((M[i][j]==-1 || sum < M[i][j]) ? sum : M[i][j]);
            }
        }
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << M[--a][--b] << "\n";
    }
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