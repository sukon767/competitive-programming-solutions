#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<ll> a(n); for(ll &i : a) cin >> i;
    vector<ll> pre(n), suf(n);
    pre[0] = a[0]; suf[n-1] = a[n-1];
    for(int i = 1; i < n; i++) pre[i] = gcd(a[i], pre[i-1]);
    for(int i = n-2; i >= 0; i--) suf[i] = gcd(a[i], suf[i+1]);

    
    ll m = 0;
    for(int i = 1; i < n; i++) m += min(pre[i], suf[i]);
    cout << m;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}