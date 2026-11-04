#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(sz(a), vector<int>(sz(b), -1));
    vector<int> prea(sz(a)), preb(sz(b));
    for(int i = 0; i < sz(a); i++) {
        if(i) prea[i] = prea[i-1];
        prea[i] = (prea[i] + (a[i]-'0'))%10;
    }
    for(int i = 0; i < sz(b); i++) {
        if(i) preb[i] = preb[i-1];
        preb[i] = (preb[i] + (b[i]-'0'))%10;
    }

    vector<vector<int>> mx1 = dp, mx = dp;

    for(int i = 0; i < sz(a); i++) {
        for(int j = 0; j < sz(b); j++) {
            if(prea[i] == preb[j]) {
                dp[i][j] = 1;
                if(i && j) dp[i][j] = max(dp[i][j], 1 + mx[i-1][j-1]);
            }

            //upd
            if(j) mx1[i][j] = mx1[i][j-1];
            mx1[i][j] = max(mx1[i][j], dp[i][j]);
            if(i) mx[i][j] = mx[i-1][j];
            mx[i][j] = max(mx[i][j], mx1[i][j]);
        }
    }

    cout << dp.back().back();
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