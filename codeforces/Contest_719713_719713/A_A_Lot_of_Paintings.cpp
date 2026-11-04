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
        int n;
        cin >> n;
        vector<int> d(n);
        for (int &i : d)
            cin >> i;
        vector<ll> lb(n), rb(n);
        ll mul = 1e7;
        ll sl = 0, sr = 0;
        for (int i = 0; i < n; i++) {
            sl += lb[i] = max(0LL, d[i] * mul - mul / 2);
            sr += rb[i] = min(mul * 100, d[i] * mul + mul / 2 - 1);
        }
        mul *= 100;
        // cout << sl << " " << sr << endl;
        if (sl <= mul && sr >= mul) {
            cout << "Yes\n";
            vector<ll> v(lb.begin(), lb.end());
            ll dif = accumulate(v.begin(), v.end(), 0LL);
            for (int i = 0; i < n; i++) {
                ll c = min(rb[i] - lb[i], mul - dif);
                dif += c;
                v[i] += c;
            }
            for (ll i : v)
                cout << i << " ";
            cout << "\n";
            // cout << endl;
            // ll sm = accumulate(v.begin(), v.end(), 0LL);
            // cout << sm << endl;
            // assert(sm > 0);
            // for (int i = 0; i < n; i++) {
            //     cout << setprecision(12) << (double)v[i] / sm * 100 << endl;
            //     assert(round((double)v[i] / sm * 100 + 1e-11) == d[i]);
            //     assert(v[i] >= 0 && v[i] <= 1e9);
            // }
        } else
            cout << "No\n";
    }
}