#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll n; cin >> n;
    const ll L = 25;
    vector<ll> ans(L);
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        vector<ll> ops(L);
        ops[0] = __builtin_popcountll(x) + (63-__builtin_clzll(x));
        ll cop = 0;
        for(ll b = 0; b+1 < L; b++) {
            if(x>>b&1) {
                x += (1LL<<b);
                cop += (1LL<<b);
            }
            ops[b+1] = __builtin_popcountll(x) + (63-__builtin_clzll(x)) + cop;
        }
        for(ll i = L-2; i >= 0; i--) {
            ops[i] = min(ops[i], ops[i+1]);
        }
        for(ll i = 0; i < L; i++) ans[i] += ops[i];
    }
    ll cnt = LLONG_MAX;
    for(ll i = 0; i < L; i++) {
        cnt = min(cnt, ans[i] - (n-1)*i);
    }

    cout << cnt;
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