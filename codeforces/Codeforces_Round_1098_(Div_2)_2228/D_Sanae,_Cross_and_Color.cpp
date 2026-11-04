#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<vector<int>> y(n);
    vector<bool> xs(n);

    for(int i = 0; i < n; i++) {
        int r, s; cin >> r >> s;
        y[--s].push_back(--r);
        xs[r] = true;
    }
    

    int on = 0;
    vector<int> cmp(n, -1);
    for(int i = 0; i < n; i++) {
        if(xs[i]) {
            cmp[i] = on;
            on++;
        }
    }

    vector<pair<int, int>> pre(n, {INT_MAX, INT_MIN}), suf(n, {INT_MAX, INT_MIN});
    for(int i = n-1; i >= 0; i--) {
        if(i < n-1) pre[i] = pre[i+1];
        for(int x : y[i]) {
            pre[i] = {min(pre[i].first, x), max(pre[i].second, x)};
        }
    }

    for(int i = 0; i < n; i++) {
        if(i) suf[i] = suf[i-1];
        for(int x : y[i]) {
            suf[i] = {min(suf[i].first, x), max(suf[i].second, x)};
        }
    }

    ll ans = 0;
    for(int i = n-1; i > 0; i--) {
        if(!sz(y[i])) continue;
        if(pre[i].first >= n || pre[i].second < 0 || suf[i-1].first >= n || suf[i-1].second < 0) continue;

        ans += max(0, cmp[min(suf[i-1].second, pre[i].second)] - cmp[max(suf[i-1].first, pre[i].first)]);
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