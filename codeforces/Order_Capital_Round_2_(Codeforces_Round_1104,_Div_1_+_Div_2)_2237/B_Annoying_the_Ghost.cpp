#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(auto& p : a) cin >> p;
    for(auto& p : b) cin >> p;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int ind = -1;
        for(int j = 0; j < sz(a); j++) {
            if(a[j] <= b[i]) {ind = j; break;}
        }
        if(ind==-1) {cout << -1; return;}
        ans += ind;
        a.erase(a.begin()+ind);
    }
    
    cout << ans;
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