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
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    int p = 0;
    while (t) {
        // a[0], a[2], ... a[2*p-2] = 0
        ll ops = min(t, 2 * p >= n ? oo : 1LL << p) - 1;
        for (int i = 0; i < p; i++) {
            a[2 * i] = (ops >> i) & 1;
            if (2 * i + 1 < n)
                a[2 * i + 1] += ops >> (i + 1);
        }
        t -= ops;
        ll cnt = 1;
        for (ll &i : a) {
            i++;
            cnt--;
            if (cnt == 0) {
                if (i == 1)
                    break;
                else {
                    cnt = i;
                    i = 0;
                }
            }
        }
        t--;
        if (2 * p < n && a[2 * p] == 0)
            p++;
    }
    for (ll i : a)
        cout << i << " ";
    cout << "\n";
}