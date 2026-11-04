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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n, k, m;
        cin >> n >> k >> m;
        ll o = 1;
        ll h = n / k - 1;
        ll v = n - n / k;
        ll t = min(v, m);
        v -= t;
        m -= t;
        o += t;
        t = min(h, m);
        h -= t;
        m -= t;
        o += t;
        cout << o + h / 2 << "\n";
    }
}