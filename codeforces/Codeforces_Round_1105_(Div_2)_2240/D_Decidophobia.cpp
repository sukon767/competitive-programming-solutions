#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, d; cin >> n >> d;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    vector<ll> w(n); for(int i = 0; i < n; i++) w[i] += (2*d+1)*a[i];
    partial_sum(all(a), a.begin());
    for(int i = 0; i < n; i++) {
        int l = (i-d+n)%n, r = (i+d)%n;
        if(l > r) {
            w[i] -= a.back() - (l?a[l-1]:0);
            w[i] -= a[r];
        } else {
            w[i] -= a[r] - (l?a[l-1]:0);
        }
    }
    sort(all(w));
    ll ans = 0;
    for(ll&x : w) {
        if(x > 0) ans+=x;
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