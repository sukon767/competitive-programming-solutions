#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<ll>> p(n, vector<ll>(4));
    for(auto& v : p) for(auto& i : v) cin >> i;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(p[i][1] > p[i][3]) ans += p[i][0];
        else ans += max(0LL, p[i][0]-p[i][2]);
        ans += max(0LL, p[i][1]-p[i][3]);
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