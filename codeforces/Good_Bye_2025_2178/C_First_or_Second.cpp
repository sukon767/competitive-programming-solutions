#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<ll> a(n), suf(n), pre(n);
    for(ll &i : a) cin >> i;
    pre[0] = a[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + abs(a[i]);
    suf[n-1] = -a[n-1];
    for(int i = n-2; i >= 0; i--) suf[i] = suf[i+1] - a[i];
    ll ans = LLONG_MIN;
    // cout << "aasdf" << endl;
    for(int i = 0; i < n; i++) {
        ll cont = 0;
        if(i < n-1) cont += suf[i+1];
        if(i) {
            cont += pre[i-1];
        }
        ans = max(ans, cont);
    }

    cout << ans;

}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}