#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n); for(ll &i : a) cin >> i;
    vector<ll> pre(n); pre[0] = a[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1]+a[i];
    vector<ll> ases(q);
    vector<vector<pair<int, int>>> que(n);
    for(int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; que[--u].push_back({--v, i});
    }
    vector<int> stk;
    vector<ll> suf;
    for(int i = n-1; i >= 0; i--) {
        while(stk.size() && a[i] > a[stk.back()]) {stk.pop_back(); suf.pop_back();}
        ll x = n-i;
        if(stk.size()) x -= n-stk.back();
        if(stk.size()) suf.push_back(suf.back());
        else suf.push_back(0);
        suf.back() += x*a[i];
        stk.push_back(i);
        for(auto &p : que[i]) {
            int y = p.first;
            //binsearch on latest thing > y.
            // slightly cut into the next index.
            int l = -1, r = stk.size()-1;
            while(l < r) {
                int mid = (l+r+1)>>1;
                if(stk[mid] > y) l = mid;
                else r = mid-1;
            }
            //l is latest suf > y.
            ll ans = suf.back();
            if(l != -1) ans -= suf[l];
            if(l+1 < stk.size()) ans -= a[stk[l+1]]*((l != -1 ? stk[l] : n)-1-y);
            ans -= pre[y];
            if(i) ans += pre[i-1];
            ases[p.second] = ans;
        }
    }
    for(ll x : ases) cout << x << "\n";
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
