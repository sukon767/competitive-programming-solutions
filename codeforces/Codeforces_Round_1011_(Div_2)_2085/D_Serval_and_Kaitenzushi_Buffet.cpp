#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i].first;
        t[i].second = i;
    }

    // cout << "asdf" << endl;

    sort(t.begin(), t.end(), [](auto &a, auto &b) {
        if(a.first > b.first) return true;
        else if(a.first < b.first) return false;
        else if(a.second < b.second) return true;
        return false;
    });

    // cout << "asdf" << endl;
    set<int> left;
    for(int i = k+1; i <= n; i+=k+1) left.insert(i);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        // cout << i << endl;
        if(!left.size()) break;
        int j = n-t[i].second;
        auto it = left.upper_bound(j);
        if(it != left.begin()) {
            it--;
            left.erase(it);
            ans += t[i].first;
        }
    }

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