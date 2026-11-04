#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    if(n == 3) {
        cout << "1 1 2 1 2 3 1 3 2 2 3 3 ";
        return;
    }
    if(n==5) {
        cout << "5 3 2 4 1 2 2 4 4 5 3 5 2 1 3 1 5 4 1 3 ";
        return;
    }

    if(n%2) cout << n << " ";
    for(int i = 1; i <= n/2*2; i++) {
        int j = i + (i%2 ? 1 : -1);
        cout << i << " " << j << " " << j << " " << i << " ";
        if(i==2 && n%2) cout << n << " ";
    }
    if(n%2) cout << n << " " << n << " ";
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