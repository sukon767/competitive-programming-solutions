#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n); vector<int> b(n);
    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] < b[i]) {ok = 0; break;}
    }

    if(ok) {
        cout << accumulate(all(a), 0) - accumulate(all(b), 0);
        return;
    } else {
        sort(all(a)); sort(all(b));
        for(int i = 0; i < n; i++) {
            if(a[i] < b[i]) {
                cout << -1; return;
            }
        }
        cout << accumulate(all(a), 0) - accumulate(all(b), 0) + c;
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