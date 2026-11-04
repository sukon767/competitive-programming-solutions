#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, k; cin >> n >> k;
    int b = 0;
    ll ans = 0;
    while(1) {
        bool ok = 1;
        for(int i = 0; i < k; i++) {
            if(n < (1LL<<b)) {
                ok = 0;
                break;
            }
            ans++;
            n -= (1LL << b);
        }
        if(!ok) break;
        b++;
    }
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