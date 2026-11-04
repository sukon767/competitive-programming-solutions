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
    vector<ll> a(n); for(ll& i : a) cin >> i;
    int z0 = 0;
    vector<int> r, s;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i]);
        if(a[i] == 0) {z0++; continue;}
        if((a[i]>0)^(i&1)) r.push_back(abs(a[i]));
        else s.push_back(abs(a[i]));
    }

    // cout << sz(r) << " " << sz(s) << " " << ans << endl;

    //r is godo on evens.
    sort(all(r));
    sort(all(s));
    for(int i = 0; i < sz(r) - (n/2 + (n&1)); i++) ans -= 2*r[i];
    for(int i = 0; i < sz(s) - (n/2); i++) ans -= 2*s[i];

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