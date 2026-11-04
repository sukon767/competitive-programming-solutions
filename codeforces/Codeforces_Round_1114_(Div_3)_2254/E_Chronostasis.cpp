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
    vector<ll> b(n); for(ll& i : b) cin >> i;
    multiset<ll> bs;
    for(int i = 0; i < n; i++) {
        bs.insert(b[i]);
    }
    
    vector<ll> ans;
    ll lo = 1, hi = *prev(bs.end()) + 1;
    while(lo < hi) {
        ll m = (lo+hi)>>1; bool ok = 1;
        multiset<ll> lft = bs;
        vector<ll> a(n);
        auto itt = lft.lower_bound(m);
        a[0] = *itt; lft.erase(itt);
        for(int i = 1; i < n; i++) {
            ll lim = 1-a[i-1];
            auto it = lft.lower_bound(lim);
            if(it == lft.end()) {
                ok = 0; break;
            }
            a[i] = a[i-1] + *it;
            lft.erase(it);
        }

        if(ok) {
            hi = m;
            ans = a;
        } else lo = m+1;
    }

    if(sz(ans) == 0) cout << -1;
    else {
        for(ll x : ans) cout << x << " ";
    }
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