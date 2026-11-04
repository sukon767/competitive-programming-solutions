#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    ll ind = -1; ll m = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i]*b[i]-c[i] > m && a[i]*b[i]-c[i] > 0) {
            ind = i; m = a[i]*b[i]-c[i];
        }
    }

    ll ans = 0;
    ll on = 0;
    for(int i = 0; i < n; i++) {
        on += a[i]*(b[i]-1);
    }

    if(on >= x) {cout << 0; return;}
    if(ind == -1) {cout << -1; return;}

    ans += (x-on)/m; on += (x-on)/m*m;
    if(on < x) ans++;
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