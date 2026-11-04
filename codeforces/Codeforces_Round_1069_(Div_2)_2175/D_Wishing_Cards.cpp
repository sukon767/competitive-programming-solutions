#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<pair<int, int>> b;
    b.push_back({a[0],1});
    for(int i = 1; i < n; i++) {
        if(a[i] > b.back().first) {b.push_back({a[i],1});}
        else b.back().second++;
    }

    // for(auto x : b) cout << x.first << " " << x.second << endl;
    
    //total, max + a prefix max
    vector<vector<int>> dp(k+1, vector<int>(k+2, -1));
    dp[0][0] = dp[0][k+1] = 0;
    for(int i = 0; i < b.size(); i++)
        for(int x = k; x > 0; x--) {
            for(int m = 1; m <= min(b[i].first, x); m++) {
                if(dp[x-m][k+1] < 0) continue;
                dp[x][m] = max(dp[x-m][k+1], dp[x][m]) + b[i].second*m;
                dp[x][k+1] = max(dp[x][k+1], dp[x][m]);
                // cout << i << " " << k << " " << m << endl;
            }

        }
            
    int ans = 0;
    for(auto x : dp) for(int y : x) ans = max(ans, y);
    cout << ans;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}