#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    ll x0 = 0, x1 = 0;
    for(int i = 0; i < n; i++) {
        if(!(i%2)) x0 += a[i];
        else x1 += a[i];
    }
    if(n%2) {
        cout << "YES";
    } else {
        if(x1 >= x0) cout << "YES";
        else cout << "NO";
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