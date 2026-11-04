#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int p, q; cin >> p >> q;
    ll c = 2*(p+2*q)+1;

    int n = 0, m = (c-1)/2;

    for(ll i = 2; i*i <= c; i++) {
        if(c%i == 0 && i%2 == 1) {
            n = (i-1)/2, m = (c/i-1)/2;
        }
    }

    if(!n || p < abs(m-n)) {
        cout << -1;
    } else cout << n << " " << m;
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