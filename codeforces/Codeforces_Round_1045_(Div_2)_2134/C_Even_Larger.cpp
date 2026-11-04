#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll& i : a) cin >> i;
    ll ans = 0;
    for(int i = 0; i+1 < n; i+=2) {
        ans += max(0LL, a[i]-a[i+1]);
        a[i] = min(a[i], a[i+1]);
    }
    for(int i = 2; i < n; i+=2) {
        ans += max(0LL, a[i]-a[i-1]);
        a[i] = min(a[i], a[i-1]);
    }

    // cout << ans << endl;

    vector<vector<ll>> runs;
    vector<ll> cur;
    for(int i = 1; i < n; i+=2) {
        if(a[i] < a[i-1] + (i+1<n ? a[i+1]:0)) {
            cur.push_back(a[i-1] + (i+1<n ? a[i+1]:0) - a[i]);
        } else {
            if(sz(cur)) runs.push_back(cur);
            cur.clear();
        }
    }

    if(sz(cur)) runs.push_back(cur);



    for(auto& v : runs) {
        for(int i = 0; i < sz(v); i++) {
            if(i+1 < sz(v)) {
                ll x1 = min(v[i], v[i+1]);
                v[i]-=x1, v[i+1]-=x1; ans+=x1;
            }
            ans += v[i];
        }
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