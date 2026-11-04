#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n = 7;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int ans = 0;
    sort(a.begin(), a.end());
    for(int x : a) ans += -x;
    ans += 2*a.back();
    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    // int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}