#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;


void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    for(int t = 0; t < q; t++) {
        int l, r; cin >> l >> r;
        l--; r--;
        int N = r-l+1;
        vector<int> lps(N, 0), dp(N, 1);
        ll ans = 1;

        for (int i = 1; i < N; i++) {
            int j = lps[i-1];
            while (j > 0 && s[l+i] != s[l+j])
                j = lps[j-1];
            if (s[l+i] == s[l+j])
                j++;
            lps[i] = j;

            if(j) {
                dp[i] = dp[i-j] + dp[j-1];
            }

            ans += dp[i];
        }
    
        cout << ans << "\n";
    }
    
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