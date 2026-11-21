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
    vector<ll> a(n); for(ll& i : a) cin >> i;
    int l = 0, r = n-1;
    vector<ll> pre(n);
    partial_sum(all(a), pre.begin());
    ll ans = pre.back();
    while(l+1 < r) {
        //>l to < r.
        // cout << l << " " << r << endl;
        ll t1 = pre.back() - (pre[r-1] - pre[l]);
        ll t2 = max(pre[r-1], pre.back() - pre[l]);
        ans = min(ans, max(t1, t2));
        //mv

        if(pre[l] <= pre.back() - pre[r-1]) l++;
        else r--;
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