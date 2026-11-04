#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
    int d = min((x1-x2+n)%n, (x2-x1+n)%n);

    if(!k) {
        cout << d; return;
    }
    if(n <= 3) {
        cout << 1; return;
    }
    
    if(d <= n/2) {
        k--;
    }
    ll t = 1 + k + d;

    cout << t;
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