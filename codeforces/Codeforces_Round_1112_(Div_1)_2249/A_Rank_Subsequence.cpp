#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<vector<int>> bd(n, vector<int>(4));
    for(auto& v : bd) {
        for(auto& i : v) cin >> i;
    }

    vector<int> dp(n+2, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 2; j <= n+1; j++) {
            if((dp[j] < bd[i][0] || bd[i][1] < dp[j]) && (j-dp[j] < bd[i][2] || bd[i][3] < j-dp[j])) {
                dp[j]++;
            }
        }
    }

    int ans = 0;
    for(int i = n+1; i >= 2; i--) {
        if(dp[i] >= i) {
            ans = i-1; break;
        }
    }
    cout << ans;
}

//king of the sun o_O
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