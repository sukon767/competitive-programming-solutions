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
    int n, k; cin >> n >> k;
    ll ans = 0;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    k--;
    if(k <= n-1-k) {
        for(int i = k; i <= n-1-k; i++) ans += a[i];
        //to k-1 and around.
        for(int i = 0; i < k; i++) {
            ans += max(a[i], a[n-1-i]);
        }
    } else {
        for(int i = k; i < n; i++) {
            ans += max(a[i], a[n-1-i]);
        }
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