#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, c, k; cin >> n >> c >> k;
    vector<ll> a(n); for(ll &i : a) cin >> i;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(c < a[i]) break;
        ll r = min(k, c-a[i]);
        // cout << c << " "a[i] << endl;
        a[i] += r;
        k -= r;
        c += a[i];
    }

    cout << c;
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