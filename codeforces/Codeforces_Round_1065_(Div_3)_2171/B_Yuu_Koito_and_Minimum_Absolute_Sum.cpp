#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    for(int i = 1; i < n-1; i++) {
        if(a[i] == -1) a[i]++;
    }
 
    if(a[0] == -1) {
        if(a.back() == -1) {
            a[0] = a.back() = 0;
        } else {
            a[0] = a.back();
        }
    } else if(a.back() == -1) {
        a.back() = a[0];
    }
    cout << abs(a.back() - a[0]) << "\n";
    for(int x : a) cout << x << " ";
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