#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    ll n; cin >> n;
    ll N = 0;
    ll l = 0;
    vector<pair<ll, ll>> ts; 
    for(ll i = 0; i < n; i++) {ll a, b; cin >> a >> b; ts.push_back({b, a}); N +=a;}
    sort(ts.begin(), ts.end());
    ll amt = 0, ans = 2*N;
    for(ll i = 0; i < N; i++) {
        // cout << i << endl;
        while(l < ll(ts.size()) && ts[l].first <= i) {amt += ts[l].second; l++;}
                // cout << amt << " " << i << endl;

        if(amt) {ll prog = min(N-i, amt); amt -= prog; ans-= prog; i--; i+=prog;}
        else if(l < ll(ts.size())) i = ts[l].first-1;
        else break;
    }

    cout << ans;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    // ll t; cin >> t;
    ll t = 1;
    for(ll i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}