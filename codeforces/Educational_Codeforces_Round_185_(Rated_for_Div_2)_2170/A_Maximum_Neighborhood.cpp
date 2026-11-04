#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    int on = 1;
    for(auto& v : g) for(auto& i : v) {
        i = on; on++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll x = g[i][j] + (i > 0 ? g[i-1][j] : 0) + (i < n-1 ? g[i+1][j] : 0) + (j > 0 ? g[i][j-1] : 0) + (j < n-1 ? g[i][j+1] : 0);
            ans = max(ans, x);
        }
    }
    cout << ans;
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