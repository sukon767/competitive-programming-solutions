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
vector<pair<int, int>> d4 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string t = "YOKOHAMA";
    vector<string> s(n);
    for (auto &a : s)
        cin >> a;
    vector<vector<ll>> dp(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == t[0])
                dp[i][j] = 1;
    for (int x = 1; x < t.size(); x++) {
        vector<vector<ll>> dp2(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == t[x]) {
                    for (auto [x, y] : d4) {
                        x += i;
                        y += j;
                        if (x >= 0 && y >= 0 && x < n && y < m)
                            dp2[i][j] += dp[x][y];
                    }
                }
        dp = dp2;
    }
    ll ans = 0;
    for (auto &a : dp)
        ans += accumulate(a.begin(), a.end(), 0LL);
    cout << ans << "\n";
}