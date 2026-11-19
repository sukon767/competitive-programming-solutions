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
    
    ll ans = INT_MAX;
    for(int tc = 0; tc < 2; tc++) {
        pair<ll, int> bst = {0, 0};
        vector<ll> pre(n-1);
        for(int i = 0; i+1 < n; i++) {
            pre[i] = abs(a[i]-a[i+1]);
            bst = max(bst, {pre[i], i});
            if(i) pre[i] = max(pre[i], pre[i-1]);
        }
        
        // ind-1 ind ind+1 ...
        //ind to 0

        ans = min(ans, bst.f);
        int ind = bst.s;
        // cout << ind << endl;
        // cout << ans << endl;
        ll tst = 0;
        for(int i = ind+1; i+1 < n; i++) tst = max(tst, abs(a[i]-a[i+1]));
        for(int i = ind; i >= 0; i--) {
            if(i < ind) tst = max(tst, 2*abs(a[i]-a[i+1]));
            ll tr = tst;
            if(ind+1 < n) tr = max(tr, abs(2*a[i]-a[ind+1]));
            if(i-1 >= 0) tr = max(tr, abs(a[i-1]-2*a[ind]));
            if(i-2 >= 0) tr = max(tr, pre[i-2]);
            ans = min(ans, tr);
        }

        reverse(all(a));
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