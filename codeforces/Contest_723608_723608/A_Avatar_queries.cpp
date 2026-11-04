#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n), pre(n); for(ll& i : a) cin >> i;
    partial_sum(all(a), pre.begin());
    ll mx = pre.back();
    vector<ll> ans(n, LLONG_MIN);
    for(int i = n-1; i >= 0; i--) {
        if(i+1 < n) ans[i] = max(ans[i], ans[i+1]);
        mx = max(mx, pre[i]);
        ans[i] = max(ans[i], mx - (i?pre[i-1] : 0));
    }
    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << ans[x] << "\n";
    }
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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