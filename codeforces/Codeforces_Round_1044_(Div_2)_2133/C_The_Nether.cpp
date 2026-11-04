#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    int mx = 0;
    vector<vector<int>> len(n+1);
    for(int i = 1; i <= n; i++) {
        cout << "? " << i << " " << n;
        for(int j = 1; j <= n; j++) cout << " " << j;
        cout << endl;
        int l; cin >> l;
        len[l].push_back(i);
        mx = max(mx, l);
    }

    vector<int> ans = {len[mx][0]};
    for(int i = mx-1; i >= 1; i--) {
        for(int j : len[i]) {
            //query
            cout << "? " << ans[0] << " " << sz(ans)+1 << " " << j;
            for(int x : ans) cout << " " << x;
            cout << endl;
            int l; cin >> l;
            if(l == sz(ans)+1) {
                ans.push_back(j);
                break;
            }
        }
    }
    cout << "! " << sz(ans);
    for(int x : ans) cout << " " << x;
    cout << endl;
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