#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> ac(n);
    for(auto &i : ac) cin >> i.first >> i.second;
    sort(ac.begin(), ac.end());

    ll c = ac[0].first + ac[0].second, ans = ac[0].second;
    for(int i = 1; i < n; i++) {
        // cout << c << endl;
        if(c < ac[i].first) {ans += ac[i].first-c;}
        c = max(c, ac[i].first+ac[i].second);
        ans += ac[i].second;
    }

    cout << ans;

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