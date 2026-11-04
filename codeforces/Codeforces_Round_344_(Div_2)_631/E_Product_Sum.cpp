#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

ld ge(pair<ll, ll> a, pair<ll, ll> b) {
    return ld(b.first-a.first)/(a.second-b.second);
}

void solve() {
    int n; cin >> n;
    vector<ll> p(n); for(ll& i : p) cin >> i;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<pair<ll, ll>> s;
    for(int i = 0; i < n; i++) s.push_back({p[i]-(i?p[i-1]:0), i});
    sort(s.begin(), s.end());

    ll ans2 = 0;
    for(int i = 0; i < n; i++) ans2 += s[i].first*(s[i].second+1);
    
    ll ans = 0;

    deque<pair<ll, ll>> hull;

    for(int i = n-1; i >= 0; i--) {
        pair<ll, ll> ln = {-p[i], i};
        while(sz(hull)>1 && ge(ln, hull[0]) >= ge(hull[0], hull[1])) hull.pop_front();
        hull.push_front(ln);
    }

    for(int i = n-1; i >=0; i--) {
        auto& [aj, j] = s[i];
        ll t = p[j] - j*aj;
        while(sz(hull)>1 && aj <= ge(hull[sz(hull)-2], hull.back())) hull.pop_back();
        ans = max(ans, t + hull.back().first + hull.back().second*aj);
    }

    hull.clear();
    for(int i = n-1; i >= 0; i--) {
        pair<ll, ll> ln = {-(i?p[i-1]:0), i};
        while(sz(hull)>1 && ge(ln, hull[0]) >= ge(hull[0], hull[1])) hull.pop_front();
        hull.push_front(ln);
    }

    for(int i = n-1; i >=0; i--) {
        auto& [aj, j] = s[i];
        ll t = (j?p[j-1]:0) - j*aj;
        while(sz(hull)>1 && aj <= ge(hull[sz(hull)-2], hull.back())) hull.pop_back();
        ans = max(ans, t + hull.back().first + hull.back().second*aj);
    }
    
    cout << ans2+ans;
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