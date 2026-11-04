#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i :a) cin >> i;
    ll MOD = 998244353;
    vector<vector<int>> lps(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        int len = 0;
        for(int j = i+1; j < n; j++) {
            while(len > 0 && a[j] != a[i+len]) len = lps[i][i+len-1];
            if(a[j] == a[i+len]) len++;
            lps[i][j] = len;
        }
    }
        

    vector<ll> dp(n+1); dp[0] = 1;
    for(int j = 0; j < n; j++)
        for(int i = 0; i <= j; i++)
            if(!lps[i][j]) dp[j+1] = (dp[j+1] + dp[i])%MOD;

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