#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll d, a, o, da, doo;
    cin >> d >> a >> o >> da >> doo;
    cout << setprecision(30) << 100.0*max(0LL, a - da*d)/ld(max(0LL, a - da*d) + max(0LL, o - doo*d));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}