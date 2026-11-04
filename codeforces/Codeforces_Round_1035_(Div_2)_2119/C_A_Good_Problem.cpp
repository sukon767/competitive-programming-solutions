#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if(n%2==1) cout << l;
    else {
        if(__builtin_clzll(l)==__builtin_clzll(r) || n==2) cout << -1;
        else if(n-k >= 2) cout << l;
        else cout << (1LL << (64-(__builtin_clzll(l))));
    }
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