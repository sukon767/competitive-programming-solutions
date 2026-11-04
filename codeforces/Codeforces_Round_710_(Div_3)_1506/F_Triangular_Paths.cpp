#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> rc(n);
    for(pair<int, int> &i : rc) cin >> i.first;
    for(pair<int, int> &i : rc) cin >> i.second;
    rc.push_back({1, 1});

    ll ans = 0;
    sort(rc.begin(), rc.end());
    for(int i = 1; i < n+1; i++) {
        int s1 = (rc[i].first - rc[i].second)/2;    int s2 = (rc[i-1].first - rc[i-1].second)/2;
        if(s2 == s1 && !((rc[i].first - rc[i].second)%2)) {ans += rc[i].first - rc[i-1].first;}
        else    ans += s1-s2;
    }
    cout << ans;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}