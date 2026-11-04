#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    int a, b, c; a = b = c = 0;
    for(int bit = 0; bit < 31; bit++) {
        if(((1 << bit) & x) == (1 << bit)) {
            a |= (1 << bit); b |= (1 << bit);
        }
        if(((1 << bit) & y) == (1 << bit)) {
            c |= (1 << bit); b |= (1 << bit);
        }
        if(((1 << bit) & z) == (1 << bit)) {
            a |= (1 << bit); c |= (1 << bit);
        }
    }
    // cout << a << " " << b << " " << c << "\n";
    // cout << (a&b == x) << " " << (b&c == y) << " " << (a&c == z)<< "\n";

    // cout << y << " " << (b&c) << "\n";

    if(((a&b) == x) && ((b&c) == y) && ((a&c) == z))    cout << "YES";
    else cout << "NO";
    return;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}