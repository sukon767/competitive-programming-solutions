#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n-1), d(n), deg(n);
    for(int& i : p) {cin >> i; i--;}
    vector<int> f(n); f[0] = 1;

    for(int i = 0; i < n-1; i++) {
        // cout << i+1 << " " << p[i] << " " << d[p[i]] << endl;
        d[i+1] = d[p[i]]+1;
        f[d[i+1]]++;
        deg[i+1]++; deg[p[i]]++;
    }

    // cout << "asdf" << endl;

    int mn = n;
    for(int i = 1; i < n; i++) {
        if(deg[i] == 1 && (mn==n || d[i] < d[mn])) mn = i;
    }


    vector<bool> dp(k+1); dp[0] = 1;
    int cur = 0;
    int ans = 0;
    for(int i = 0; i <= d[mn]; i++) {
        // cout << f[i] << " " << d[mn] << endl;
        cur += f[i];

        for(int j = k; j >= f[i]; j--) {
            dp[j] = dp[j] || dp[j-f[i]];
        }

        for(int j = max(0, cur-(n-k)); j <= k; j++) {
            if(dp[j]) {
                ans = max(ans, i+1); break;
            }
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