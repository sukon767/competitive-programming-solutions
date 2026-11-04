#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    map<int, vector<pair<int, int>>> pts;
    for(int i =0; i < n; i++) {
        int x, y; cin >> x >> y;
        pts[max(x, y)].push_back({x, y});
    }

    for(auto &x : pts)
        sort(x.second.begin(), x.second.end(), [](const pair<int, int> &a, const pair<int, int> &b) {if(a.first == b.first) return a.second > b.second; return a.first < b.first;});

    vector<ll> dp(6);
    for(auto v : pts) {
        pair<int, int> l = v.second.front(), r = v.second.back();
        pair<ll, ll> lc = {dp[1], dp[2]}, rc = {dp[4], dp[5]};
        ll d = abs(l.first - r.first) + abs(l.second - r.second);
        vector<ll> t(6);

        t[1] = l.first, t[2] = l.second, t[4] = r.first, t[5] = r.second;
        t[0] = d + min(dp[0] + abs(lc.first-r.first) + abs(lc.second-r.second), dp[3] + abs(rc.first-r.first) + abs(rc.second-r.second));
        t[3] = d + min(dp[0] + abs(lc.first-l.first) + abs(lc.second-l.second), dp[3] + abs(rc.first-l.first) + abs(rc.second-l.second));

        dp = t;
    }

    cout << min(dp[0], dp[3]);
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