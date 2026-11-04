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
    int n, c;
    ll p, q;
    cin >> n >> c >> p >> q;
    vector<ll> arr(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        arr[i] = (s[i] == 'Y' ? q : 0) - p;
    partial_sum(arr.begin(), arr.end(), arr.begin());
    int ans = 0;
    ll mn = 0;
    for (int i = c - 1; i < n; i++) {
        if (arr[i] >= mn) {
            ans++;
            mn = oo;
            i += c - 1;
        }
        uMin(mn, arr[i - c + 1]);
    }
    cout << ans << "\n";
}