#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n, k; cin >> n >> k;
    ll l = 1, r = 1e18;
    vector<ll> a(n); for(ll &i : a) cin >> i;
    if(a[0]!= 1) {cout << 1; return;}

    while(l < r) {
        ll x = n-1;
        ll m = l + ((r-l+1)>>1);
        ll mm = m;
        
        for(ll i = 0; i < k; i++) {
            if(!mm) break;
            while(a[x] > mm) x--;
            mm -= x+1;
        }

        if(mm) r = m-1;
        else l = m;
    }

    cout << l+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    for(ll i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}