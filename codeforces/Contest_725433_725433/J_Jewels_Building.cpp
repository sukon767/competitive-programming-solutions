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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m); for(int &i : a) cin >> i;
    for(int& i : b) cin >> i;

    vector<vector<bool>> dp(n+1, vector<bool>(m+1));
    vector<int> first(m+1, INT_MAX); first[0] = 0;
    dp[0][0] = 1;
    for(int j = 1; j <= m; j++) {
        for(int i = 1; i <= n; i++) {
            if(a[i-1] == b[j-1] && dp[i-1][j-1]) {
                dp[i][j] = 1;
                first[j] = min(first[j], i);
            }
            if(first[j-1] <= i-b[j-1])  {
                dp[i][j] = 1;
                first[j] = min(first[j], i);
            }
        }
    }

    cout << (dp.back().back() ? "YES" : "NO");
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