#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n); for(ll &i : a) cin >> i; for(ll &i : b) cin >> i;
    k %= 2;
    vector<ll> p(n), s(n); p[0] = a[0]; s[n-1] = a[n-1];

    for(ll i = 1; i < n; i++) p[i] = p[i-1]+a[i];
    for(ll i = n-2; i >= 0; i--) s[i] = s[i+1]+ a[i];

    p[0] = min(0LL, p[0]); s[n-1] = min(0LL, s[n-1]);
    for(ll i = 1; i < n; i++) p[i] = min(p[i-1], p[i]);
    for(ll i = n-2; i >= 0; i--) s[i] = min(s[i+1], s[i]);

    ll total = 0;
    for(ll x : a) total += x;


    ll ans = LLONG_MIN;
    if(!k) {
        for(ll i = 0; i < n; i++)
            ans = max(ans, total - (i==0 ? 0 : p[i-1]) - (i==n-1 ? 0 : s[i+1]));
        
    } else {
        for(ll i = 0; i < n; i++) {
            ans = max(ans, b[i] + total - (i==0 ? 0 : p[i-1]) - (i==n-1 ? 0 : s[i+1]));
        }
            
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