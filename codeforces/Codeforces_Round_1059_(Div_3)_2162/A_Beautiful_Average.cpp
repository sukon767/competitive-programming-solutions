#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        int ans = 0, n; cin >> n;
        vector<int> a(n); for(int &i : a) cin >> i;
        for(int x : a) ans = max(ans, x);
        cout << ans;
        cout << "\n";
    }
}