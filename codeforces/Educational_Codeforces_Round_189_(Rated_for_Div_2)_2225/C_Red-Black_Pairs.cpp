#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    vector<int> dp(n);
    if(s1[0] != s2[0]) {dp[0] = 1;}

    for(int i = 1; i < n; i++) {
        int r = 0, b = 0;
        
        if(s1[i] == 'R') r++;
        else b++;
        if(s2[i] == 'R') r++;
        else b++;
        
        dp[i] = dp[i-1] + min(r, b);
    
        int x = 0;
        if(s1[i-1] != s1[i]) x++;
        if(s2[i-1] != s2[i]) x++;

        dp[i] = min(dp[i], (i > 1 ? dp[i-2] : 0) + x);
    }

    // for(int i = 0; i < n; i++) cout << i << " " << dp[i] << endl;

    cout << dp.back();
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