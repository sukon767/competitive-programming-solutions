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
const int N = 3e5;
vector<pair<int, ll>> g[N];
ll d1[N];
pair<ll, int> d2[N];
ll ret[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
            g[i].clear();
        fill(d1, d1 + n, oo);
        d1[0] = 0;
        for (int i = 0; i < n; i++)
            d2[i] = {oo, -1};
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            a--;
            d2[a] = {0, i};
            pq.push({0, a});
        }
        fill(ret, ret + n, 0LL);
        while (m--) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            w *= 2;
            g[--u].push_back({--v, w});
            g[v].push_back({u, w});
        }
        while (pq.size()) {
            auto [d, c] = pq.top();
            pq.pop();
            if (d != d2[c].a)
                continue;
            for (auto &[i, w] : g[c])
                if (d2[i].a > d + w) {
                    d2[i] = {d + w, d2[c].b};
                    pq.push({d + w, i});
                }
        }
        pq.push({0, 0});
        while (pq.size()) {
            auto [d, c] = pq.top();
            pq.pop();
            if (d != d1[c])
                continue;
            for (auto &[i, w] : g[c])
                if (d1[i] > d1[c] + w)
                    pq.push({d1[i] = d1[c] + w, i});
        }
        ll tm = 0;
        for (int i = 0; i < n; i++)
            if (d2[i].a == 0)
                uMax(tm, d1[i]);
        for (int i = 0; i < n; i++)
            for (auto &[j, w] : g[i])
                if (d2[i].b != d2[j].b && d1[i] + d2[j].a + w <= tm) {
                    ll x = (d2[j].a + w - d2[i].a) / 2;
                    x = max(x, 0LL);
                    x = min(x, w);
                    ll mx = (tm - d1[i] - d2[i].a) / 2;
                    x = min(x, mx);
                    if (x < 0)
                        continue;
                    ll t = tm - max(d2[i].a + x, d2[j].a + w - x);
                    uMax(ret[d2[i].b], t);
                    uMax(ret[d2[j].b], t);
                }
        for (int i = 0; i < k; i++)
            cout << ret[i] / 2 << (ret[i] % 2 == 0 ? ".0 " : ".5 ");
        cout << "\n";
    }
}