// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T> T uMin(T &a, T b) { return a = min(a, b); }
template <class T> T uMax(T &a, T b) { return a = max(a, b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++) {
            dp[i][j] = s.substr(i, j - i + 1);
            int len = j - i + 1, b = -1;
            for (int k = i; k < j; k++) {
                int c = dp[i][k].size() + dp[k + 1][j].size();
                if (c < len) {
                    len = c;
                    b = k;
                }
            }
            if (b != -1)
                dp[i][j] = dp[i][b] + dp[b + 1][j];
            len = dp[i][j].size();
            b = -1;
            for (int r = 2; r < 10; r++)
                if ((j - i + 1) % r == 0) {
                    int l = (j - i + 1) / r;
                    bool w = 1;
                    for (int k = i + l; k <= j && w; k++)
                        w = s[k] == s[k - l];
                    if (!w)
                        continue;
                    if (dp[i][i + l - 1].size() + 3 < len) {
                        l = dp[i][i + l - 1].size() + 3;
                        b = r;
                    }
                }
            if (b != -1)
                dp[i][j] = to_string(b) + "(" + dp[i][i + (j - i + 1) / b - 1] + ")";
        }
    cout << dp[0][n - 1] << "\n";
}