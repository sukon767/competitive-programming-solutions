#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> box(n, array<int, 3>{});
    for (int i = 0; i < n; i++) {
        cin >> box[i][0] >> box[i][1] >> box[i][2];
        sort(box[i].begin(), box[i].end());
    }
    array<int, 3> mn{INT_MAX, INT_MAX, INT_MAX};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            mn[j] = min(mn[j], box[i][j]);
        }
    }
    cout << mn[0] * mn[1] * mn[2] << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
