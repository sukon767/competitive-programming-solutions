#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll a, b; cin >> a >> b;
    if(a==b) {
        cout << a; return;
    }
    for(int c = 60; c >= 0; c--) {
        if((a>>c&1) != (b>>c&1)) {
            if((a&((1LL<<c)-1)) == 0) {
                cout << a; return;
            } else {
                for(int d = c-1; d >= 0; d--) {
                    if(a>>d&1) {
                        ll z = a>>d<<d;
                        if((a&((1LL<<d)-1)) == 0) cout << z;
                        else {
                            z ^= (1LL << (d+1));
                            z ^= (1LL << d);
                            cout << z;
                        }
                        return;
                    }
                }
            }
        }
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