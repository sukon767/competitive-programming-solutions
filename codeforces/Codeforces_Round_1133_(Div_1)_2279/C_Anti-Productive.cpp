#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

ll isqrt(ll N) {
    ll lo = 0, hi = 1e9;
    while(lo < hi) {
        ll mid = (lo+hi+1)>>1;
        if(mid*mid <= N) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

//sukon always reads the entire problem statement.
void solve() {
    int n, l; cin >> n >> l;
    l--;
    vector<ll> a(n); for(ll &i : a) cin >> i;
    sort(all(a));
    vector<ll> pre(n); partial_sum(all(a), pre.begin());
    if(a[sz(a)-2]*a[sz(a)-1] <= l) {
        cout << 0; return;
    }

    ll ans = LLONG_MAX;

    ll sl = isqrt(l);
    ll mx = a.back();
    
    auto check = [&](ll x) {
        if(x>sl||x<0) return;
        //relieve
        ll c2 = distance(lower_bound(all(a), x), a.end()) - 1;
        ll c = pre[n-2] - (n-1-c2>0 ? pre[n-1-c2-1] : 0) - c2*x;
        if(x) c += max(0LL, mx - l/x);
        ans = min(ans, c);
    };
    check(0); check(sl);
    for(int i = -2; i <= 2; i++) check(l/mx+i);
    for(ll x : a) check(x);

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