#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int t; cin >> t;
    if(t <= 6*60) {
        cout << 0;
    } else if(t <= 6*60 + 30) {
        cout << t - 6*60;
    } else if(t <= 9*60 + 30) {
        cout << 30;
    } else if(t <= 9*60 + 45) {
        cout << t - 9*60;
    } else if(t <= 10*60 + 45) {
        cout << 45;
    } else cout << t - 10*60;
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