#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

const ll MOD = 1e9+7;

void solve() {
    int q; cin >> q;

    vector<pair<ll, int>> bin = {{3LL, 0}};
    for(ll y = 2; y <= 60; y++) {
        ll yy = 1, z = 0;
        while(yy <= (1LL << y)/y) {z++; yy *= y;}
        bin.push_back({(1LL << y), z});
        if(yy <= ((1LL << (y+1)) - 1)/y) bin.push_back({yy*y, z+1});
    }

    for(int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;
        ll ans = 0;
        for(int i = 0; i < sz(bin)-1; i++) {
            ll t = (max(0LL, min(r, bin[i+1].first-1) - max(l-1, bin[i].first-1)) + MOD)%MOD*bin[i].second%MOD;
            ans = (ans+t)%MOD;
        }

        cout << ans << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

/* new testament
 * nick belov always reads the entire problem statement.
 */