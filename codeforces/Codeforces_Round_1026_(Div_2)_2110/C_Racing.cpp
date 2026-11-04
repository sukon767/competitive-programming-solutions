#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for(int &i : d) cin >> i;
    vector<pair<int, int>> lr(n);
    for(auto &p : lr) {
        cin >> p.first >> p.second;
    }
 
    for(int i = 1; i < n; i++) {
        lr[i].first = max(lr[i-1].first + (d[i] == 1 ? 1 : 0), lr[i].first);
    }
 
    for(int i = n-2; i >= 0; i--) {
        lr[i].second = min(lr[i+1].second - (d[i+1] == 1 ? 1 : 0), lr[i].second);
    }
 
    vector<int> ans(n+1);
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] == 1 || (d[i] == -1 && cur+1 <= lr[i].second)) {
            cur++;
        }
 
        if(!(lr[i].first <= cur && cur <= lr[i].second)) {
            cout << -1;
            return;
        }
 
        ans[i+1] = cur;
    }
 
    for(int i = 1; i <= n; i++) cout << ans[i]-ans[i-1] << " ";
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