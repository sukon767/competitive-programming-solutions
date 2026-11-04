#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (ll)(x).size()

void solve() {
    ll n; cin >> n;
    vector<ll> a(n-1), b(n);
    for(ll& i : a) cin >> i;
    for(ll& i : b) cin >> i;

    int L = 34;

    vector<ll> dp(L);
    vector<ll> vp(L), v(L);
    for(ll i = 0; i < n; i++) {
        ll nec = (i<n-1?a[i]:0LL)|(i?a[i-1]:0LL);
        v[0] = b[i];
        for(ll j = L-1; j >= 0; j--) {
            if((nec>>j&1) && !(v[0]>>j&1)) {
                v[0] |= (1LL<<j);
                v[0] &= ~((1LL<<j)-1);
            }
        }

        for(ll j = 1; j < L; j++) {
            v[j]=v[j-1];
            if(!(nec>>(j-1)&1) && (v[j]>>(j-1)&1)) {
                v[j] += (1LL<<j);
                v[j] &= ~((1LL<<j)-1);
            }
            v[j]|=nec;
        }

        vector<ll> t(L, LLONG_MAX>>2);
        for(ll j = 0; j < L; j++) {
            for(ll l = 0; l < L; l++) {
                if(!i || (vp[j]&v[l])==a[i-1]) {
                    t[l]=min(t[l], dp[j]+(v[l]-b[i]));
                }
            }
        }
        
        dp = t; vp = v;
    }

    ll ans = *min_element(dp.begin(), dp.end());
    cout << (ans==LLONG_MAX>>2?-1:ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */