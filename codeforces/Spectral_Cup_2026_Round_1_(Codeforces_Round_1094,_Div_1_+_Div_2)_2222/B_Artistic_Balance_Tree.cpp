#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), x(m); for(int& i : a) cin >> i;
    int odd = 0;
    for(int& i : x) {cin >> i; i--; if(i%2) odd++;}
    ll ans = 0;

    vector<int> e, o;
    for(int i = 0; i < n; i++) {
        if(i%2) o.push_back(a[i]);
        else e.push_back(a[i]);
    }

    sort(e.begin(), e.end());
    sort(o.begin(), o.end());

    reverse(e.begin(), e.end()); reverse(o.begin(), o.end());

    for(int i = 0; i < min(sz(o), odd); i++) {
        if(i && o[i] < 0) break;
        ans -= o[i];
    }

    for(int i = 0; i < min(sz(e), m-odd); i++) {
        if(i && e[i] < 0) break;
        ans -= e[i];
    }

    for(int x : a) ans += x;

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