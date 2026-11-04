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
    ll n, c; cin >> n >> c;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    sort(all(a));
    ll sm = accumulate(all(a), (ll)0);
    ll ans = sm - n*c;
    for(int i = 0; i < n/2; i++) {
        sm -= a[i];
        ans = max(ans, sm-(n-1-i)*c);
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