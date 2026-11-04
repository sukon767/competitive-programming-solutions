#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    for(int i = 0; i < n; i++) {
        vector<ll> ub(n, 0);
        // cout << endl << "aaaa" << endl;
        for(int j = i+1; j < i+n; j++) {
            ub[j%n] = max(a[(j-1)%n], ub[(j-1)%n]);
        }
        for(int j = i-1; j > i-n; j--) {
            ub[(j+n)%n] = min(max(a[(j+n)%n], ub[(j+1+n)%n]), ub[(j+n)%n]);
        }
        
        ll s = accumulate(ub.begin(), ub.end(), 0LL);
        cout << s << " ";
        // for(int j = 0; j < n; j++) {
        //     cout << ub[j] << " ";
        // }
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