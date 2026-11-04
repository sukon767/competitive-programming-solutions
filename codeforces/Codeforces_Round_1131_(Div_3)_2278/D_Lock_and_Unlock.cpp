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
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(all(a));
    ll op = a.back() - a[0];
    vector<ll> pre(n); partial_sum(all(a), pre.begin());
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, (i*a[i] - (i?pre[i-1]:0)) + (pre.back()-pre[i] - (n-1-i)*a[i]));
    }

    cout << ans << " " << op;
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