#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    cout << (1 << n) -1 << ' ';
    for(int bit = 0; bit < n; bit++) {
        for(int i = 0; i < (1<<bit); i++) {
            cout << (1 << (n-bit-1)) - 1 + i*(1<<(n-bit)) << " ";
        }
    }
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}