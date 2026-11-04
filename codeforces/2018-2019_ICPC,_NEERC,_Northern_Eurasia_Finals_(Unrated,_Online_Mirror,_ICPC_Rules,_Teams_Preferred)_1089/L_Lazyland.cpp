#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> b(n);
    vector<vector<ll>> cont(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i].second;
    }
    for(auto& [aa, bb] : b) cont[--aa].push_back(bb);
    for(auto& v : cont) sort(v.begin(), v.end());
    vector<ll> bst;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j+1 < sz(cont[i]); j++) bst.push_back(cont[i][j]);
        if(sz(cont[i])) k--;
    }

    sort(bst.begin(), bst.end());
    ll ans = 0;
    for(int i = 0; i < k; i++) ans += bst[i];
    
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