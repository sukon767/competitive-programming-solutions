#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i :a) cin >> i;
    if(n==1) {
        cout << 0; return;
    }
    int xo = 0;
    for(int x : a) xo^=x;

    int ans = 0;
    for(int y : a) {
        if((xo^y) < y) {
            ans++;
        }
    }

    cout << ans + bool(xo==0);
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