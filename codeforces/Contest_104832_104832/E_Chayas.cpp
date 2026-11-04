// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T> T uMin(T &a, T b) { return a = min(a, b); }
template <class T> T uMax(T &a, T b) { return a = max(a, b); }
const int N = 24;
ll dp[1 << N];
bool can[1 << N][N];
int num, val;
bool vis[N];
vector<pair<int, bool>> g[N];
bool dfs(int s) {
    vis[s] = 1;
    num |= 1 << s;
    for (auto &[i, f] : g[s]) {
        bool to = ((val >> s) & 1) != f;
        if (vis[i]) {
            if (((val >> i) & 1) != to)
                return 0;
        } else {
            if (to)
                val |= 1 << i;
            if (!dfs(i))
                return 0;
        }
    }
    return 1;
}
int comps[1 << N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(m, vector<int>(3));
    for (auto &a : e)
        for (int &i : a)
            cin >> i, i--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            g[j].clear();
        for (auto &a : e) {
            if (a[1] == i) {
                g[a[0]].push_back({a[2], 1});
                g[a[2]].push_back({a[0], 1});
            } else if (a[0] == i || a[2] == i) {
                int o = a[0] == i ? a[2] : a[0];
                g[o].push_back({a[1], 0});
                g[a[1]].push_back({o, 0});
            }
        }
        fill(vis, vis + n, 0);
        val = 0;
        comps[0] = 0;
        int sz = 1;
        for (int j = 0; j < n; j++)
            if (j != i && !vis[j]) {
                num = 0;
                if (!dfs(j)) {
                    cout << "0\n";
                    return 0;
                }
                for (int j = 0; j < sz; j++)
                    comps[j + sz] = comps[j] ^ num;
                sz *= 2;
            }
        for (int j = 0; j < sz; j++)
            can[comps[j] ^ val][i] = 1;
    }
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if (can[i][j])
                dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % mod;
    cout << dp[(1 << n) - 1] << "\n";
}