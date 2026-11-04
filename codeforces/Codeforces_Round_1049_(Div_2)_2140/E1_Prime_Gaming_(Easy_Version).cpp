#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, m; cin >> n >> m;
    int k; cin >> k;


    vector<int> c(k); for(int& i : c) {cin >> i; i--;}

    if(m == 1) {cout << 1; return;}

    vector<vector<bool>> dp(n+1);
    
    dp[1] = {0, 1};

    for(int i = 2; i <= n; i++) {
        dp[i] = vector<bool>(1 << i);
        for(int j = 0; j < (1<<i); j++) {

            if((n-i)%2) dp[i][j] = 1;
            else dp[i][j] = 0;

            for(int l : c) {
                if(l >= i) break;


                int st = (j & ((1<<l)-1)) | ((j>>(l+1))<<l);



                if((n-i)%2) {
                    //bobs turn so take 0
                    if(dp[i-1][st] == 0) {dp[i][j] = 0; break;}
                } else {
                    if(dp[i-1][st] == 1) {dp[i][j] = 1; break;}
                }
            }

        }
    }

    int ans = (1 << n);
    for(int j = 0; j < (1 << n); j++) {
        if(dp[n][j]) ans++;
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