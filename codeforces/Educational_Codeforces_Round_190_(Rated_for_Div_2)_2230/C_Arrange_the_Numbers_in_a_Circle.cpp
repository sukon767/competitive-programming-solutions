#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n; cin >> n;
    vector<ll> c(n); for(ll& i : c) cin >> i;
    ll ans = 0;

    ll t1 = 0;
    ll m1 = 0;
    ll amt = 0;

    for(ll& x : c) {
        if(x > 1) {
            ans += x;
            m1 += x/2 -1;
            amt++;
        }
        else t1++;
    }

    ll ans2 = 0;
    if(amt == 1) ans2 =  ans + min(t1, m1+1);
    else ans2 = ans + min(t1, m1);

    if(ans2 < 3) cout << 0;
    else cout << ans2;
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
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