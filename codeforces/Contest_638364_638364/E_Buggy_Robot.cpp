#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    int dirx = 0; int diry = 0;
    for(int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if(t == 'L')    dirx++;
        if(t == 'R')    dirx--;
        if(t == 'U')    diry++;
        if(t == 'D')    diry--;
    }

    cout << n - abs(dirx) - abs(diry);

    return 0;
}

int main() {
    // int t; cin >> t;

    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}