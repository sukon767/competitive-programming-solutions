#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> d(n); for(int& i : d) cin >> i;
    for(int i = 0; i < n-1; i++) d[i] = d[i+1]-d[i];
    d.pop_back();
    int prev = 0;
    ll hi = LLONG_MAX, lo = 0;
    ll cur = 0;
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(i%2==prev%2) {
            cur += d[i];
            hi = min(hi, cur);
        } else {
            cur -= d[i];
            lo = max(lo, cur);
        }

        if(lo >= hi) {
            ans += i-prev-1;
            prev = i;
            cur = d[i];
            lo = 0, hi = cur;
        }
    }
    ans += n-1-prev;
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