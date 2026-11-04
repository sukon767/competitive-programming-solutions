#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    for(int i = 1; i < n; i++)  a[i]+=a[i-1];
    ll sum = a[n-1];
    int ans = 0;
    for(int i = 0; i < n-1; i++)
        if(2*a[i] == sum)   ans++;

    cout << ans;

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