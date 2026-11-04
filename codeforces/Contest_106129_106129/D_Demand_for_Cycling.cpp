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
    cin >> n;
    ll mnx = oo, mny = oo, mxx = -oo, mxy = -oo;
    while (n--) {
        ll x, y;
        cin >> x >> y;
        uMin(mnx, x);
        uMin(mny, y);
        uMax(mxx, x);
        uMax(mxy, y);
    }
    cout << "4\n"
         << mnx << " " << mny << "\n"
         << mxx << " " << mny << "\n"
         << mxx << " " << mxy << "\n"
         << mnx << " " << mxy << "\n";
}