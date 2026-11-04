#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, c; cin >> n >> c;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    int ans = 0;
    sort(a.begin(), a.end()); reverse(a.begin(), a.end());

    while(sz(a)) {
        for(int i = 0; i < sz(a); i++) {
            if(i==sz(a)-1 || a[i]<=c) {
                if(a[i] > c) ans++;
                a.erase(a.begin()+i);
                break;
            }
        }
        for(auto& x : a) x<<=1; 
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