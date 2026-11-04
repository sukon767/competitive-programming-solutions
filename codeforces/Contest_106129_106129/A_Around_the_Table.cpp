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
    ll a, b;
    cin >> a >> b;
    if (a == b)
        cout << a * 3;
    else if (a == b + 1)
        cout << a * 2 - 1;
    else if (a == b + 2)
        cout << (a - 1) * 3;
    else
        cout << (a + b) * 2;
    cout << "\n";
}