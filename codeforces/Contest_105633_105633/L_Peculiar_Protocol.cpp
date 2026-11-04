#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll n, d, r; cin >> n >> d >> r;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    map<ll, int> mp;
    for(int i = 1; i <= n; i++) {
        if(mp.find(r*i%d) != mp.end()) break;
        mp[r*i%d] = i;
    }
    ll g = d/gcd(r, d);
    vector<ll> pre(n); partial_sum(all(a), pre.begin());

    vector<vector<int>> dp(n, vector<int>(n));
    auto fl = dp;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j+i-1 < n; j++) {
            int k = j+i-1;
            if(j < k) dp[j][k] = dp[j][k-1];
            for(int l = j+1; l <= k; l++) dp[j][k] = max(dp[j][k], dp[j][l-1]+fl[l][k]);
            ll s = (pre[k]-(j?pre[j-1]:0))%d;
            if(mp.find(s) != mp.end()) {
                int b = mp[s];
                if(1+dp[j][k]>=b) {
                    fl[j][k] = (1+dp[j][k]-b)/g*g + b;
                }
            }
            dp[j][k] = max(dp[j][k], fl[j][k]);
            // cout << j << " " << k << " " << fl[j][k] << endl;
        }
    }

    vector<ll> dp2(n);
    for(int j = 0; j < n; j++) {
        if(j) dp2[j] = dp2[j-1];
        for(int i = 0; i <= j; i++) {
            if(fl[i][j]) {
                ll s = pre[j]-(i?pre[i-1]:0);
                ll c = mp[s%d];
                dp2[j] = max(dp2[j], (i?dp2[i-1]:0) + (s - c*r)/d);
            }
        }
    }

    cout << dp2.back();
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */