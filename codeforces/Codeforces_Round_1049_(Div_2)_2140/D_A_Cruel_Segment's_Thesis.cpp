#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> lr(n);
    for(auto& [l, r] : lr) cin >> l >> r;
    sort(lr.begin(), lr.end(), 
    [&](auto &a, auto &b) {
        if(a.second < b.first) return true;
        if(b.second < a.first) return false;
        return a.first+a.second < b.first+b.second;
    }        
);

    // for(auto& [l, r] : lr) {
    //     cout << l << " " << r << endl;
    // }

    ll ans = 0;
    for(int i = 0; i < n-1-i; i++) {
        ans += lr[i].second+lr[n-1-i].second-lr[i].first-lr[n-1-i].first;
        ans += lr[n-1-i].second-lr[i].first;
    }
    if(n%2) {
        ans += lr[n/2].second - lr[n/2].first;
        ll binc = 0;
        for(int i = 0; i < n/2; i++) {
            binc = max(binc, lr[i].first-lr[n/2].first);
        }

        for(int i = n/2+1; i < n; i++) {
            binc = max(binc, lr[n/2].second - lr[i].second);
        }

        ans += binc;
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