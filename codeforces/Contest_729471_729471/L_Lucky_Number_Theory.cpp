#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define retp(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;

vector<vector<ld>> dp;
void solve () {
    int n, k, d; cin >> n >> k >> d;
    cout << fixed << setprecision(12) << dp[n][k]+(ld)n*d/2;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);

    const int n = 2000;
    dp = vector<vector<ld>>(n+1, vector<ld>(n+1));
    for(int i = 1; i <= n; i++) {
        dp[i][1] = 0.5;
        dp[i][i] = 0.5*i;
    }

    for(int j = 2; j <= n; j++) {
        for(int i = j+1; i <= n; i++) {
            ld x = 1 + dp[i-1][j-1] - dp[i-1][j];
            dp[i][j] = x*((1-x/2) + dp[i-1][j-1]) + (1-x)*dp[i-1][j];
        }
    }

    // for(int i = 1; i <= 5; i++) {
    //     for(int j = i; j <= 5; j++) {
    //         cout << i << " " << j << ' ' << dp[i][j] << endl;
    //     }
    // }


    int t; cin >> t;
    // int n = 1;
    while(t--) solve();
}