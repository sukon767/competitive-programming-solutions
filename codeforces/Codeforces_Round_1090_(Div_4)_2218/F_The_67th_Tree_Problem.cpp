#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int x, y; cin >> x >> y;
    if(!x && (y%2 == 0)) {
        cout << "NO";
        return;
    }

    if(x > y) {cout << "NO"; return;}
    int d = y-x;
    if(!(d%2)) {
        x--;
    }
    //1, 0, 3, 2, 5, 4, etc.
    d ^= 1;
    cout << "YES\n";
    for(int i = 0; i < x; i++) {
        cout << 1+2*i << " " << 1+2*i+1 << "\n";
        cout << 1+2*i+1 << " " << 1+2*i+2 << "\n";
    }
    for(int i = 2; i <= d+1; i++) {
        cout << 1 << " " << 2*x+i << "\n";
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