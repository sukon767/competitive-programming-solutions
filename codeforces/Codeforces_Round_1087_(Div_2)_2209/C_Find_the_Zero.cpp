#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= 2*n-2; i+=2) {
        cout << "? " << i << " " << i+1 << endl;
        int q; cin >> q;
        if(q == 1) {
            cout << "! " << i << endl;
            return;
        }
    }

    //now
    cout << "? " << 1 << " " << 2*n-1 << endl;
    int q; cin >> q;
    if(q == 1) {cout << "! " << 1 << endl; return;}

    cout << "? " << 2 << " " << 2*n-1 << endl;
    cin >> q;
    if(q == 1) cout << "! " << 2 << endl;
    else cout << "! " << 2*n << endl;
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