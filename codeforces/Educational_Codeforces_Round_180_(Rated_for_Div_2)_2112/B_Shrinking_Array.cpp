#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    for(int i = 1; i < n; i++) {
        if(abs(a[i]-a[i-1]) <= 1) {cout << 0; return;}
    }
    for(int i = 2; i < n; i++) {
        if((a[i]-a[i-1] > 0) != (a[i-1]-a[i-2] > 0)) {
            cout << 1; return;
        }
    }
    cout << -1; return;
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