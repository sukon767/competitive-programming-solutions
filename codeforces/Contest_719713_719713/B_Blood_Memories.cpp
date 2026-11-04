// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T> T uMin(T &a, T b) { return a = min(a, b); }
template <class T> T uMax(T &a, T b) { return a = max(a, b); }
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    vector<vector<ll>> c(a.size(), vector<ll>(b.size(), -oo));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            for (int k = 0; k < a.size(); k++)
                uMax(c[i][k], a[i][j] + b[j][k]);
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, r;
        cin >> n >> m >> k >> r;
        vector<pair<ll, int>> v(n);
        for (auto &a : v)
            cin >> a.a >> a.b;
        vector<vector<ll>> mat(1 << n, vector<ll>(1 << n)), ret(1 << n, vector<ll>(1 << n, -oo));
        for (int i = 0; i < (1 << n); i++)
            ret[i][i] = 0;
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < (1 << n); j++) {
                int c = 0;
                ll q = 0;
                for (int x = 0; x < n; x++)
                    if ((j >> x) & 1) {
                        c += v[x].b + ((i >> x) & 1) * k;
                        q += v[x].a;
                    }
                mat[i][j] = c <= m ? q : -oo;
            }
        while (r) {
            if (r & 1)
                ret = mul(ret, mat);
            mat = mul(mat, mat);
            r /= 2;
        }
        cout << *max_element(ret[0].begin(), ret[0].end()) << "\n";
    }
}