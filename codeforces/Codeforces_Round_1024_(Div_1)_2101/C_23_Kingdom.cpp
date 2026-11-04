#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    set<int> cur;
    vector<int> pre(n), suf(n);
    for(int i = 1; i <= n; i++) cur.insert(i);
    for(int i = 0; i < n; i++) {
        auto it = cur.upper_bound(a[i]);
        if(i) pre[i] = pre[i-1];
        if(it != cur.begin()) {
            pre[i]++;
            cur.erase(--it);
        }
    }
    cur.clear();
    for(int i = 1; i <= n; i++) cur.insert(i);
    for(int i = n-1; i >= 0; i--) {
        auto it = cur.upper_bound(a[i]);
        if(i < n-1) suf[i] = suf[i+1];
        if(it != cur.begin()) {
            suf[i]++;
            cur.erase(--it);
        }
    }

    // for(int i = 0; i < n; i++) cout << i << " " << pre[i] << ' ' << suf[i] << endl; 

    ll ans = 0; int m = 0;
    for(int i = 0; i < n; i++) {ans += min(pre[i], suf[i]); m = max(m, min(pre[i], suf[i]));}
    cout << ans-m;
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