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
    int n; cin >> n; n = (1<<n);
    vector<ll> a(n); for(ll &i : a) cin >> i;
    vector<vector<array<ll, 4>>> dp(2*n); //sum, prefix, suffix, subarray.
    for(int i = n; i < 2*n; i++) {
        ll z = max(a[i-n], 0LL);
        dp[i] = {{a[i-n], z, z, z}};
    }
    for(int i = n-1; i > 0; i--) {
        dp[i].resize(2*sz(dp[i<<1]));
        for(int t = 0; t < 2; t++) {
            for(int j = 0; j < sz(dp[i<<1]); j++) {
                auto &x = dp[i<<1][j]; auto &y = dp[i<<1|1][j];
                dp[i][t*sz(dp[i<<1])+j] = {x[0] + y[0], max(x[1], x[0] + y[1]), max(x[2] + y[0], y[2]), max({x[3], y[3], x[2] + y[1]})};
            }
            swap(dp[i<<1], dp[i<<1|1]);
        }
    }

    int c = 0;
    int q; cin >> q;
    while(q--) {
        int k; cin >> k; c ^= (1<<k);
        cout << dp[1][c][3] << "\n";
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