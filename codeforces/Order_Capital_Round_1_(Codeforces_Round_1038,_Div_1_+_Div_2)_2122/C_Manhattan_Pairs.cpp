#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<ll>> pts(n, vector<ll>(3));
    for(auto& p : pts) cin >> p[0] >> p[1];
    for(int i = 0; i < n; i++) pts[i][2]=i;
    sort(pts.begin(), pts.end());
    deque<pair<ll, int>> s1, s2;
    for(int i = 0; i < n/2; i++) s1.push_back({pts[i][1], pts[i][2]});
    for(int i = n/2; i < n; i++) s2.push_back({pts[i][1], pts[i][2]});

    vector<pair<int, int>> ans;
    sort(s1.begin(), s1.end()); sort(s2.begin(), s2.end());
    while(sz(s1)) {
        if(s1.back().first > s2.back().first) swap(s1, s2);
        ans.push_back({s1.front().second, s2.back().second});
        s1.pop_front(), s2.pop_back();
    }
    for(auto& p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */