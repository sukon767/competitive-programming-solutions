#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    if(!(n%3))  cout << 0;
    else cout << 3 - (n%3);
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