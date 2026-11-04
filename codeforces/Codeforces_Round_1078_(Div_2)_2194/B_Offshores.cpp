#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int i = 0; i < n; i++) b[i] = a[i]/x*y;
    ll tot = 0;
    for(int x : b) tot+=x;
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, tot - b[i] + a[i]);
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