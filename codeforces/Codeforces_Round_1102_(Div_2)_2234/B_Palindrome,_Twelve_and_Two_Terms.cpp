#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<ll> pal;

void solve() {
    ll n; cin >> n;
    if(pal[n%12] <= n) {
        cout << pal[n%12] << " " << n-pal[n%12];
    } else cout << -1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pal = vector<ll>(12, INT_MAX);
    for(ll i = 0; i <= 22; i++) {
        string s;
        ll k = i;
        while(k) {
            s += k%10; k /= 10;
        }
        bool ok = true;
        for(int j = 0; j < sz(s); j++) {
            if(s[j] != s[sz(s)-1-j]) {
                ok = false; break;
            }
        }
        if(ok) pal[i%12] = min(pal[i%12], i);
    }

    // for(int i = 0; i < 12; i++) cout << pal[i] << endl;


    int t; cin >> t;
    // int t = 1;
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