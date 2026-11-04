#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(ll &i : a) cin >> i; for(ll &i : b) cin >> i;
    if(a[0] != b[0] || a[n-1] != b[n-1]) {cout << "No"; return;}
    map<int, int> as, bs;
    for(int i = 0; i < n-1; i++) as[a[i+1]-a[i]]++;
    for(int i = 0; i < n-1; i++) bs[b[i+1]-b[i]]++;
    for(auto p : as) if(as[p.first] != bs[p.first]) {cout << "No"; return;}
    cout << "Yes";
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