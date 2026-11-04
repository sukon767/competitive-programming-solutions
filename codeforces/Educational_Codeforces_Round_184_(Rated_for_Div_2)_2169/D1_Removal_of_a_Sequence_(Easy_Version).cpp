#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll x, y, k; cin >> x >> y >> k;
    ll n = 1e12;
    ll l = 0, r = n;
    while(l < r) {
        ll mid = l + ((r-l+1)/2);
        ll kl = mid;
        for(ll i = 0; i < x; i++)
            kl -= kl/y;
        if(kl < k) l = mid;
        else r = mid-1;
    }


    if(l == n)
        cout << -1;
    else cout << l+1;
    
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