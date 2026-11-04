#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int R, X, D, n; cin >> R >> X >> D >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1' || (s[i]=='2' && R < X)) {
            R = max(R-D, 0); ans++;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}