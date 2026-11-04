#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n; cin >> n;
    vector<ll> p(n); for(ll& i : p) {cin >> i; i--;}

    vector<ll> size(n, 1);
    vector<ll> dp(n);
    vector<ll> pt(n, -1);

    dp[0] = 1;
    if(p[1] < p[0]) {
        dp[1] = 2; pt[1] = 0;
    } else dp[1] = 1;

    ll cur = dp[0]+dp[1];
    for(ll i = 2; i < n; i++) {
        if(p[i] < p[i-1] && p[i] < p[i-2]) {
            if(dp[i-2] > dp[i-1]) {
                pt[i] = i-2; dp[i] = dp[i-2]+1;
            } else {
                pt[i] = i-1; dp[i] = dp[i-1]+1;
            }
        } else if(p[i] < p[i-2]) {
            pt[i] = i-2; dp[i] = dp[i-2]+1;
        } else {
            pt[i] = i-1; dp[i] = dp[i-1]+1;
        }

        cur += dp[i];
    }

    // for(ll i = 0; i < n; i++) {
    //     cout << i << " " << dp[i] << " " << pt[i] << endl;
    // }

    for(ll i = n-1; i >= 0; i--) {
        if(pt[i] != -1) size[pt[i]] += size[i];
    }

    // cout << 0 << " " << cur << endl;
    ll ans = cur;
    for(ll i = 1; i < n; i++) {
        //remove i-1
        cur--;
        if(pt[i]==i-1) cur -= size[i];
        if(i+1 < n && pt[i+1] == i-1) {
            cur -= size[i+1];
            if(p[i+1] < p[i]) {
                cur += size[i+1]; pt[i+1] = i;
            }
        }
        // cout << i << " " << cur << endl;

        ans += cur;
    }

    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */