#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    int ans = 0;
    int ma = abs(a[0] - a[1]);
    for(int i = 1; i < n-1; i++) {ans += abs(a[i] - a[i-1]); ma = max(ma, abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]) - abs(a[i-1] - a[i+1]));}
    ans += abs(a[n-2] - a[n-1]);
    ma = max(ma, abs(a[n-2] - a[n-1]));
    cout << ans - ma;
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