#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), p(n+1), dp(n+1);
    for(ll &i : a) cin >> i;

    set<pair<ll, ll>> th;
    th.insert({0, 0});

    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
        auto it = th.lower_bound({p[i]+1, LLONG_MIN});
        if(it == th.begin()) {
            dp[i] = dp[i-1];
        } else {
            it = prev(it);
            // cout << (*it).first << " " << (*it).second << endl;
            dp[i] = max(dp[i-1], i+(*it).second);
        }

        pair<ll, int> cur = {p[i], dp[i]-i};
        
        // cout << i << ' ' << cur.first << " " << cur.second << " " << p[i] << endl;

        it = th.lower_bound({p[i], LLONG_MIN});
        if(it != th.begin() && (*prev(it)).second >= cur.second) {
            continue;
        } else {
            //check before and pop
            while(it != th.end()) {
                if((*it).second <= cur.second) {
                    it = th.erase(it);
                } else break;
            }
        }
        th.insert(cur);

    }
    ll ans = 0;
    for(ll x : dp) ans = max(ans, x);
    cout << ans;
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