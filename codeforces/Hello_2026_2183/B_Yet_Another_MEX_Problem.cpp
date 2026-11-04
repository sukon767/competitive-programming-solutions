#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<bool> f(n+2);
    for(int i=0; i < n; i++) {
        int x; cin >> x;
        f[x] = 1;
    }
    int mx = 0;
    for(int i = 0; i <= n+1; i++) {
        if(!f[i]) {mx = i; break;}
    }
    cout << min(mx, k-1);
    
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