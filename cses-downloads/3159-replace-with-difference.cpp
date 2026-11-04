#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
void solve() {
    int n; cin >> n;
    vector<int> x(n); for(int& i : x) cin >> i;
    int sum = accumulate(all(x), 0);
    if(sum&1) {cout << -1; return;}
    const int N = 1e6;
    bitset<N+1> dp; dp[0]=1;
    vector<ll> par(N+1, -1);
    for(int i = 0; i < n; i++) {
        auto t = dp << x[i];
        auto dif = t & ~dp;
        for(int s = dif._Find_first(); s <= N; s = dif._Find_next(s)) par[s] = i;
        dp |= t;
    }
    if(!dp[sum/2]) {cout << -1; return;}
    vector<int> s, s2;
    int k = sum/2;
    while(k) {
        s.push_back(par[k]); k -= x[par[k]];
    }
    vector<bool> temp(n);
    for(int x : s) temp[x]=1;
    for(int i = 0; i < n; i++) if(!temp[i]) s2.push_back(i);
    for(int&j : s) j = x[j];
    for(int&j : s2) j = x[j];
    while(sz(s) && sz(s2)) {
        int x = s.back(), y = s2.back();
        if(x < y) {
            swap(x, y); swap(s, s2);
        }
        s.pop_back(); s2.pop_back(); s.push_back(x-y);
        cout << x << " " << y << "\n";
    }
    if(sz(s)==0) swap(s, s2);
    for(int i = 0; i+1 < sz(s); i++) cout << "0 0\n";
}
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
 /* new testament
 * nick belov always reads the entire problem statement.
 */
