#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, x, s; cin >> n >> x >> s;
    string u; cin >> u;

    ll anser = 0;
    for(int i = -1; i < n+1; i++) {
        ll ct = 0, ans = 0;
        for(int j = 0; j < n; j++) {
            if(u[j] == 'I' || (u[j] == 'A' && j <= i)) {
                if(ct < x) {
                    ct++; ans++;
                }
            } else if(u[j] == 'E' || (u[j] == 'A' && j > i)) {
                if(ct*s - ans) {
                    ans++;
                }
            }
        }
        anser = max(anser, ans);
    }

    cout << anser;
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