#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    if(k > 2*n-1 || n > k) {cout << "NO"; return;}
    cout << "YES\n";
    if(k == n) {for(int i = 1; i <= n; i++) cout << i << " " << i << " "; return;}

    for(int i = n; i > n - (2*n-1-k); i--) cout << i << " " << i << " ";
    cout << 1 << " " << 2 << " ";
    for(int i = 3; i <= n - (2*n-1-k); i++) {
        cout << i << " " << i-2 << " ";
    }
    cout << n - (2*n-1-k)-1 << " " << n - (2*n-1-k);
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