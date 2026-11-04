#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string x, y;
    cin >> x >> y;
    int firstone = 0;
    for(int i = y.size()-1; i >= 0; i--)    if(y[i] == '1') {firstone = i; break;}
    firstone = y.size()-firstone;
        // cout << firstone << "firstone" << endl;

    bool found = false;
    for(int i = x.size() - firstone; i >= 0; i--) if(x[i] == '1') {cout << (x.size() - firstone - i); return;}

    cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}