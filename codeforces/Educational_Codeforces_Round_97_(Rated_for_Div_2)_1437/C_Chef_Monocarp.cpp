#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> t(n); for(int& i : t) {cin >> i; i--;}
    sort(t.begin(), t.end());

    vector<int> dp(n+1, INT_MAX/2);
    dp[0] = 0;
    for(int i = 0; i < 2*n; i++) {
        for(int j = n; j > 0; j--) {
            dp[j] = min(dp[j], dp[j-1] + abs(t[j-1] - i));
        }
    }

    cout << dp[n];
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