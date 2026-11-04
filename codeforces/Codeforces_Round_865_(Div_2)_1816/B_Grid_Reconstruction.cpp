#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a1(n+1), a2(n+1);

    for(int i = 1; i <= n; i++) {
        if(i%2) a2[i] = i;
        else a1[i] = i;   
    }

    for(int i = 2; i < n; i++) {
        if(i%2) a1[i] = i+n-1;
        else a2[i] = i+n-1;
    }
    a1[1] = 2*n-1;
    a2[n] = 2*n;
    
    for(int i = 1; i <= n; i++) cout << a1[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << a2[i] << " ";

    //523
    //146 vs 
    //
    //514
    //236
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