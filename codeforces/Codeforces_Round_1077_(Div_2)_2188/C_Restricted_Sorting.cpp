#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;

    vector<int> b = a;
    sort(b.begin(), b.end());

    int l = b[0], r = b.back();

    vector<int> c;
    for(int i = 0; i < n; i++) if(a[i] != b[i]) c.push_back(a[i]);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
 
    int ans = INT_MIN;
    for(int i = 0; i+1 < c.size(); i++) {
        ans = max(ans, min(c[i+1]-l, r-c[i]));
    }
    if(c.size()) {
        ans = max(ans, c[0]-l);
        ans = max(ans, r-c.back());
    }
 
    if(ans == INT_MIN) cout << -1;
    else cout << ans;
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