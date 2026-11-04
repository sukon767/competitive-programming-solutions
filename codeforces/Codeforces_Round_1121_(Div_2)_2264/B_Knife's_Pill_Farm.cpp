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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    ll ans = LLONG_MIN;
    multiset<ll> bst;
    ll pref = 0;
    for(int i = 0; i+1 < m; i++) {
        bst.insert(a[i]);
        pref += a[i];
    }
    for(int i = m-1; i < n; i++) {
        ans = max(ans, m*a[i] - pref);
        pref += a[i];
        bst.insert(a[i]);
        pref -= *prev(bst.end());
        bst.erase(prev(bst.end()));
    }

    cout << ans;
}

//king of the sun o_O
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