#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    vector<ll> f;
    for(int i = 0; i < n; i++) if(!i || a[i] != a[i-1]) f.push_back(1); else f.back()++;
    sort(all(f));

    ll l = 0;
    ll acc = 0;
    ll tot = accumulate(all(f), 0LL);

    // for(int x : f) cout << x << endl;

    ll ans = 0;
    while(l < sz(f)) {
        ll ag = tot - (f[l]-1)*(sz(f)-l) - acc;
        ll b = sz(f) - l;
        if(ag <= k && (k-ag)%b==0) ans++;

        // cout << ag << " " << b << endl;

        ll zz = f[l];
        while(l < sz(f) && f[l]==zz) {
            acc += f[l];
            l++;
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