#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    sort(a.begin(), a.end());
    ll mx = a.back(); a.pop_back(); n--;

    ll lo = 0, hi = 1e12;
    while(lo < hi) {
        ll m = (lo+hi+1)>>1;
        vector<pair<int, ll>> dp(1 << n);
        for(int i = 0; i < (1 << n); i++) {
            for(int b = 0; b < n; b++) {
                if(i>>b&1) {
                    auto cont = dp[i ^ (1<<b)];
                    cont.second += a[b];
                    if(cont.second >= m) {
                        cont.first++; cont.second = 0;
                    }
                    dp[i] = max(dp[i], cont);
                }
            }
        }
        if(dp.back().first >= k) lo = m;
        else hi = m-1;

        // if(m == 7) {
        //     for(int i = 0; i < 1<<k; i++) {
        //         cout << i << " " << dp[i].first << " " << dp[i].second << endl;
        //     }

        // }
    }


    cout << lo+mx;
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