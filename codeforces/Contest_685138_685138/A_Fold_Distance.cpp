#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n,m; cin >> n >> m;
    int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
    int a = abs(r1-r2), b = abs(c1-c2);
    int ans = 0;
    if(a) ans++;
    if(a && !(a&1)) ans++;
    if(b) ans++;
    if(b && !(b&1)) ans++;
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