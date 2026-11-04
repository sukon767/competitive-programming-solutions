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
    vector<int> a(n), b(m); for(int&i : a) cin >> i;
    for(int& i : b) cin >> i;
    sort(all(b));
    int j = 0;
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        ll s = 0;
        while(j < b[i]) {s += a[j]; j++;}
        ans += abs(s);    
    }
    while(j < n) {ans += a[j]; j++;}
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