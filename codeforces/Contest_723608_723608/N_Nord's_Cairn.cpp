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
    auto ans = [&](ll n) {
        ll lo = 0, hi = 1e8;
        while(lo < hi) {
            ll m = (lo+hi+1)>>1;
            if(m*(m+1)/2 <= n) lo = m;
            else hi = m-1;
        }
        return lo;
    };

    ll L, R; cin >> L >> R;
    cout << ans(R) - ans(L-1);
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