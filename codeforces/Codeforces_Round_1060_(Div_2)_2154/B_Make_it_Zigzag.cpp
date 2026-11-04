#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a)   cin >> i;
    vector<int> pre(n); pre[0] = a[0];

    int ans = 0;

    for(int i = 1; i < n; i++) {
        pre[i] = max(pre[i-1], a[i]);
        if(i%2) {
            a[i] = pre[i];
        } else {
            if(a[i] >= a[i-1]) {
                ans += a[i] - a[i-1]+1;
                a[i] = a[i-1]-1;
            }
        }
    }

    if(a[0] == a[1])    ans++;

    cout << ans;

    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}