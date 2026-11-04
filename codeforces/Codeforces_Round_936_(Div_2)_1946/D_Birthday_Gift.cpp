#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<vector<bool>> ok(30, vector<bool>(n));

    for(int b = 0; b < 30; b++) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(!(cur%2)) ok[b][i] = 1;
            cur += a[i]>>b&1;
        }
        if(cur%2) {
            for(int i = 0; i < n; i++) ok[b][i] = 0;
        }
    }

    int k = 0;
    vector<bool> cur(n, 1);
    for(int b = 29; b >= 0; b--) {
        if(x>>b&1) {
            int ans = 0;
            for(int i = 0; i < n; i++) ans += cur[i] & ok[b][i];
            k = max(k, ans);
        } else {
            for(int i = 0; i < n; i++) cur[i] = cur[i] & ok[b][i];
        }
    }

    int l = 0; for(int i = 0; i < n; i++) l += cur[i];
    k = max(k, l);

    if(!k) cout << -1;
    else cout << k;
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