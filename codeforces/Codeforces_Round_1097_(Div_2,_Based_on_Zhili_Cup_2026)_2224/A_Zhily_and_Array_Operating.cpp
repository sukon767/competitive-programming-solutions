#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin>> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] > 0 && i) {
            a[i-1] += a[i];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) if(a[i] > 0) ans++;

    cout << ans;
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