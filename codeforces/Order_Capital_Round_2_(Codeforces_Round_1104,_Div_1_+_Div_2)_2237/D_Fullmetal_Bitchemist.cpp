#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++) {
        if(s[i]=='0') v[i].first++;
        else v[i].second++;
    }
    for(int i = 1; i < n; i++) {
        v[i].first+=v[i-1].first;
        v[i].second+=v[i-1].second;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(3)); dp[0] = {1, 0, 0};
    
    for(int i = 1; i <= n; i++) {
        dp[i]=dp[i-1];
        ll r = ((v[i-1].second-v[i-1].first)%3+3)%3;
        dp[i][r]++;
    }


    ll ans = n; int lst = -1;
    for(int i = 1; i < n; i++) {
        if(s[i]==s[i-1]) lst = i-1;
        if(lst==-1) continue;
        int r = ((v[i].second-v[i].first)%3+3)%3;
        ans += accumulate(dp[lst].begin(), dp[lst].end(), (ll)0) - dp[lst][r];
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