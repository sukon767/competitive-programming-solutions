#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, p, k; cin >> n >> p >> k;
    map<ll, ll> mp;
    vector<ll> a(n);
    for(ll& i : a) {
        cin >> i;
        mp[((i*i%p*i%p*i%p - i*k%p)%p + p)%p]++;
    }

    ll ans = 0;
    for(auto& [_, x] : mp) ans += x*(x-1)/2;

    cout << ans;
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