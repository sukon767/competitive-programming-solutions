#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, h, k; cin >> n >> h >> k;
    ll tot = 0;
    vector<ll> a(n); for(ll &i : a) {cin >> i; tot+=i;}
    vector<ll> pre(n); pre[0] = a[0];
    for(ll i = 1; i < n; i++) pre[i] = pre[i-1]+a[i];

    ll ans = 0;
    ans += h/tot*(n+k);
    h -= h/tot*tot;
    if(!h) {cout << ans - k; return;}

    ll tp = 0;
    for(ll i = 0; i < n; i++) {
        if(h <= pre[i]) {tp = i; break;}
    }

    ll mc = 0;
    for(ll i = n-1; i >= tp; i--) mc = max(mc, a[i]);


    ll minc = a[0], l = 0;
    while(l < tp) {
        minc = min(minc, a[l]);
        while(tp > l && h - (pre[tp-1] + max(0LL, mc-minc)) <= 0) tp--;
        l++;
    }
    // cout << tp << endl;
    cout << ans + tp+1;
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