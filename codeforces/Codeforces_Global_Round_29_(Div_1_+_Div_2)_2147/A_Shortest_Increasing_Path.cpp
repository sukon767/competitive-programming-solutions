#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int x, y; cin >> x >> y;
    if(y == 1) {cout << -1; return;}
    if(x ==y || x == y+1) {cout << -1; return;}
    if(x < y) {cout << 2; return;}
    cout << 3;
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