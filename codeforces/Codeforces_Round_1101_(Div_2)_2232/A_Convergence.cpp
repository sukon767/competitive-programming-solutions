#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    int x1 = 0, x2 = 0;
    for(int i = 0; i < n/2; i++) {
        if(a[i] != a[n/2]) x1++;
    }
    for(int i = n/2+1; i < n; i++) {
        if(a[i] != a[n/2]) x2++;
    }

    cout << max(x1, x2);
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