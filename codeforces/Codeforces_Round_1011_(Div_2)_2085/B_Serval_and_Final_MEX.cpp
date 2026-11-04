#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int buf = 0;
    vector<pair<int, int>> ans;
    if(a[0] || a.back()) {

        bool work = false;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                work = true;
                break;
            }
        }

        if(work) {
            cout << 2 << "\n";
            if(!a[0]) {
                cout << 1 << " " << n-1 << "\n";
            } else {
                cout << 2 << " " << n << "\n";
            }
            cout << 1 << " " << 2;
        } else {
            cout << 1 << "\n";
            cout << 1 << " " << n;
        }

    } else {
        cout << 3 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << n-1 << "\n";
        cout << 1 << " " << 2;
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