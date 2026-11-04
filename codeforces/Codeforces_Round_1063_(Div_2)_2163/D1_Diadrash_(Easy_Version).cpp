#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, q; cin >> n >> q;
    vector<int> mind(n+1, -1);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        mind[l] = max(mind[l], r);
    }

    vector<pair<int, int>> ivls;
    for(int i = 1; i <= n; i++) {
        if(mind[i] == -1) continue;
        if(!ivls.size() || mind[i] > ivls.back().second) ivls.push_back({i, mind[i]});
    }

    int x;
    cout << "? " << 1 << " " << n/2 << endl;
    cin >> x;
    int ans = 0;
    for(int i = 0; i < ivls.size(); i++) {
        if((x && ivls[i].first <= n/2) || (!x && ivls[i].second > n/2)) {
            int y; cout << "? " << ivls[i].first << " " << ivls[i].second << endl;
            cin >> y;
            ans = max(ans, y);   
        }
    }

    cout << "! " << ans << endl;
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