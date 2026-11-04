#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    ll n, k, p, q; cin >> n >> k >> p >> q;

    vector<ll> a(n); for(ll &i : a) cin >> i;
    vector<vector<ll>> pre(3, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        pre[0][i] = min(a[i]%q%p, a[i]%p);
        pre[1][i] = a[i]%q%p;
        pre[2][i] = a[i]%p;
        if(i) {
            for(int j = 0; j < 3; j++) pre[j][i] += pre[j][i-1];
        }
    }

    // for(ll x : a) cout << x << " ";
    // cout << endl;
    // cout << ans << endl;
    
    ll ans = LLONG_MAX;
    for(int i = k-1; i < n; i++) {
        // cout << i << endl;
        ll cont = min(pre[1][i] - (i-k >= 0 ? pre[1][i-k] : 0), pre[2][i] - (i-k >= 0 ? pre[2][i-k] : 0)) + pre[0].back();
        cont -= pre[0][i] - (i-k >= 0 ? pre[0][i-k] : 0);
        // cout << cont << endl;
        // cout << i << " " << pre[1][i] << endl;
        ans = min(ans, cont);
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