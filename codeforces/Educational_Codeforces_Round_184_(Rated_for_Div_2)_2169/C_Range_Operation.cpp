#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), p(n); for(ll & i : a) cin >> i;
    p[0] = a[0]; for(ll i = 1; i < n; i++) p[i] = p[i-1]+a[i];
    vector<pair<ll, ll>> l(n), r(n);
    l[0] = {0, 0};
    for(ll i = 1; i < n; i++) if(p[i-1]-i*i-i > l[i-1].second) l[i] = {i, p[i-1]-i*i-i}; else l[i] = l[i-1];
    r[n-1] = {n-1, (n-1)*(n-1) + 3*(n-1) + 2 - p[n-1]};
    // cout << r[n-1].second << " " << (n-1)*(n-1) << endl;
    for(ll i = n-2; i >= 0; i--) if(i*i + 3*i + 2 -p[i]>= r[i+1].second) r[i] = {i, i*i + 3*i + 2 -p[i]}; else r[i] = r[i+1];

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        // cout << p[n-1] << " " << l[i].second << " " << r[i].second << endl;
        ans = max(ans, p[n-1] + l[i].second + r[i].second);
        // cout << i << " " << l[i].first << " " << r[i].first << " " << (p[i]+l[i].second+r[i].second) << " " << ans << endl;

    }
    



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