#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll m = 998244353;
    ll n; cin >> n;
    map<ll, ll> a; for(ll i = 0; i < n; i++) {ll u; cin >> u; a[u]++;}
    vector<ll> cs;
    for(auto p : a) cs.push_back(p.second);
    if(cs.size() == 1) {cout << cs[0]; return;}
    sort(cs.begin(), cs.end());
    vector<ll> dp(n+1);
    dp[0] = 1; dp[cs[0]] = cs[0];


    for(ll i = 1; i < ll(cs.size()) -1; i++) {
        ll c = cs[i];
        vector<ll> t = dp;
        for(ll j = 0; j+c <= n; j++) t[j+c] = (t[j+c] + dp[j]*c%m)%m;
        // cout << c << endl;
        dp = t;
    }
    ll ans = 0;
    for(ll i = n; i >= cs.back(); i--) ans = (ans + dp[i])%m;
    
    ll c = cs.back();

    // for(ll i = 0; i <= n; i++) cout << i << " " << dp[i] << endl;

    for(ll j = 0; j <= n; j++) ans = (ans + dp[j]*c%m)%m;

    cout << ans;
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    for(ll i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}