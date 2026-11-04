#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
    int n; cin >> n;
    vector<ll> x(n);
    for(ll &i : x) cin >> i;
    sort(x.begin(), x.end());
    for(int i = 1; i < n; i++) {
        if(x[i] == x[i-1]) {cout << "1\n" << x[i] << "\n1\n" << x[i-1]; return;}
    }
    vector<pair<ll, ll>> x1 = {{0, 0}}; vector<pair<ll, ll>> x2 = {{0, 0}};
    for(int i = 0; i < n/2; i++) {
        int s = x1.size();
        for(int j = 0; j < s; j++) x1.push_back({x1[j].first + x[i], s+j});
    }
    for(int i = n/2; i < n; i++) {
        int s = x2.size();
        for(int j = 0; j < s; j++) x2.push_back({x2[j].first + x[i], s+j});
    }
    sort(x1.begin(), x1.end()); sort(x2.begin(), x2.end());
    ll l = 0, r = (1LL << n) - 2;
    ll le = 0;
    while(l < r) {
        ll cnt = 0;
        ll mid = (l+r)>>1;  
        // <= mid
        int i2 = int(x2.size())-1;
        for(int i = 0; i < x1.size(); i++) {
            while(i2 >= 0 && (x1[i].first + x2[i2].first > mid)) i2--;
            cnt += i2+1;
        }
        if(cnt-le > mid-l+1) r = mid;
        else {l = mid+1; le = cnt;}
    }
    //l has a double.
    vector<pair<int, int>> d;
    int i2 = int(x2.size())-1;
    for(int i = 0; i < x1.size(); i++) {
        while(i2 >= 0 && x1[i].first + x2[i2].first > l) i2--;
        if(i2 >= 0 && x1[i].first + x2[i2].first == l) d.push_back({x1[i].second, x2[i2].second});  
        if(d.size() == 2) break;
    }
    //recover
    set<ll> a1, a2;
    for(int i = 0; i < n/2; i++) {
        if((d[0].first >> i) & 1) a1.insert(x[i]);
        if((d[1].first >> i) & 1) a2.insert(x[i]);
    }
    for(int i = 0; i < n - n/2; i++) {
        if(d[0].second >> i & 1) a1.insert(x[i + n/2]);
        if(d[1].second >> i & 1) a2.insert(x[i + n/2]);
    }
    for(auto it = a1.begin(); it != a1.end();) {
        if(a2.find(*it) != a2.end()) {
            a2.erase(*it);
            it = a1.erase(it);
        } else it++;
    }
    cout << a1.size() << "\n";
    for(ll x : a1) cout << x << " ";
    cout << "\n" << a2.size() << "\n";
    for(ll x : a2) cout << x << " ";
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
