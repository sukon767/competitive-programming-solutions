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
    vector<ll> a(n); for(ll &i : a) cin >> i;
    vector<pair<ll, ll>> pre(n), suf(n);

    pre[0].s = a[0];
    for(int i = 1; i < n; i++) {
        pre[i].s = max(a[i], 1 + pre[i-1].s);
        pre[i].f = pre[i-1].f + (pre[i].s - a[i]);
    }

    suf.back().s = a.back();
    for(int i = n-2; i >= 0; i--) {
        suf[i].s = max(a[i], 1 + suf[i+1].s);
        suf[i].f = suf[i+1].f + (suf[i].s - a[i]);
        // cout << i << " " << suf[i].f << " " << suf[i].s << endl;
    }
    
    // for(int i = 0; i < n; i++) {
    //     cout << i << " " << pre[i].f << " " << suf[i].f << endl;
    // }

    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        ll tst = 0;
        ll mx = a[i];
        if(i) {
            tst += pre[i-1].f;
            mx = max(mx, pre[i-1].s+1);
        }
        if(i < n-1) {
            tst += suf[i+1].f;
            mx = max(mx, suf[i+1].s+1);
        }

        ans = min(ans, tst + (mx - a[i]));
    }
    cout << ans;
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