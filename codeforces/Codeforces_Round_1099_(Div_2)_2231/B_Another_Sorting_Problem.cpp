#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> b(n); for(int&i : b) cin >> i;

    int lb = 0, hb = INT_MAX;
    int cur = INT_MAX;
    for(int i = 1; i < n; i++) {
        if(b[i] < b[i-1]) {
            if(cur == -1) {
                cout << "NO"; return;
            }
            lb = max(lb, b[i-1] - b[i]);
            hb = min(hb, cur);
            cur = -1;
        } else {
            cur = max(cur, b[i] - b[i-1]);
        }
    }

    if(hb >= lb) {
        cout << "YES";
    } else cout << "NO";

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