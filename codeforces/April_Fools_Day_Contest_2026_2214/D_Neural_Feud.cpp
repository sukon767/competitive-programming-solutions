#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int v; cin >> v;
    if(v == 1) cout << "Walk";
    if(v == 2) cout << "No";
    if(v == 3) cout << "No";
    if(v == 4) cout << "No";
    if(v == 5) cout << "Yes";
    if(v == 6) cout << "Yes";
    if(v == 7) cout << "backwards";
    if(v == 8) cout << "7";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}