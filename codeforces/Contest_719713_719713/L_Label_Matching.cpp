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
const int N = 2e5;
int a[N], b[N];
vector<int> g[N];
int n;
bool r[N];
map<int, int> cnt[N];
int pt;
pair<pair<int, pair<int, int>>, pair<int, int>> dfs(int s, int p) {
    int a0 = a[s] == 0, b0 = b[s] == 0;
    int ind = pt++;
    if (a[s] != b[s]) {
        if (a[s] != 0)
            cnt[ind][a[s]]++;
        if (b[s] != 0)
            cnt[ind][b[s]]--;
    }
    pair<int, int> pn = {0, 0};
    for (auto &[_, a] : cnt[ind])
        if (a > 0)
            pn.a += a;
        else
            pn.b -= a;
    for (int i : g[s])
        if (i != p) {
            auto [at, x] = dfs(i, s);
            auto [p, sm] = at;
            a0 += x.a;
            b0 += x.b;
            if (cnt[p].size() > cnt[ind].size()) {
                swap(ind, p);
                swap(sm, pn);
            }
            for (auto &a : cnt[p]) {
                if (cnt[ind].find(a.a) != cnt[ind].end()) {
                    if (cnt[ind][a.a] > 0)
                        pn.a -= cnt[ind][a.a];
                    else
                        pn.b += cnt[ind][a.a];
                }
                cnt[ind][a.a] += a.b;
                if (cnt[ind][a.a] == 0)
                    cnt[ind].erase(a.a);
                else if (cnt[ind][a.a] > 0)
                    pn.a += cnt[ind][a.a];
                else
                    pn.b -= cnt[ind][a.a];
            }
        }
    r[s] = pn.a <= b0 && pn.b <= a0;
    return {{ind, pn}, {a0, b0}};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        pt = 0;
        for (int i = 0; i < n; i++) {
            g[i].clear();
            cnt[i].clear();
        }
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
        }
        dfs(0, -1);
        for (int i = 0; i < n; i++)
            cout << r[i];
        cout << "\n";
    }
}