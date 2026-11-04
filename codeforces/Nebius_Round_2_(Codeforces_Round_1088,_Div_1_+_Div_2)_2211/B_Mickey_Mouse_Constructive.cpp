#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int x, y; cin >> x >> y;

    int d = 0;
    for(int i = 1; i <= abs(x-y); i++) if(!(abs(x-y)%i)) d++;

    cout << max(d, 1) << "\n";
    if(x < y) {
        for(int i = 0; i < x; i++) cout << 1 << " ";
        for(int i = 0; i < y; i++) cout << -1 << " ";
    } else {
        for(int i = 0; i < y; i++) cout << -1 << " ";
        for(int i = 0; i < x; i++) cout << 1 << " ";
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