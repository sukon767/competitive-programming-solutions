#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> q(n), r(n); for(ll& i : q) cin >> i;
    for(ll& i : r) cin >> i;
    sort(q.begin(), q.end()); sort(r.begin(), r.end());

    int ri = -1;
    vector<ll> cur;
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        while(ri < n-1 && (r[ri+1]+1)*(q[i]+1) <= k+1) {
            ri++; cur.push_back(r[ri]);
        }
        if(sz(cur)) {
            ans++; cur.pop_back();
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