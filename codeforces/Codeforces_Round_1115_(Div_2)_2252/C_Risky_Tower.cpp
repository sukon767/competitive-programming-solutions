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
    int n, m; cin >> n >> m;
    vector<ll> v(n); for(ll& i : v) cin >> i;
    vector<vector<ll>> a(n, vector<ll>(m)); for(auto& v : a) for(auto&i : v) cin >> i;
    multiset<ll> cur;
    int ans = m;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) cur.insert(a[i][j]);
        ll k = v[i];
        auto it = prev(cur.end());
        for(int j = 0; j < m; j++) {
            k -= *it;
            if(k <= 0) {
                ans = min(ans, j+1); break;
            }
            it = prev(it);
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