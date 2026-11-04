#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int x1 = 0, x2 = 0;
    for(int& i : a) {cin >> i; x1+=i;}
    for(int& i : b) {cin >> i; x2+=i;}
    if(x1%2 == x2%2) {cout << "Tie"; return;}
    for(int i = n-1; i >= 0; i--) {
        if(a[i] != b[i]) {
            if(i%2) {
                cout << "Mai";
            } else {
                cout << "Ajisai";
            }
            return;
        }
    }

    if(x1%2) cout << "Ajisai";
    else cout << "Mai";
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