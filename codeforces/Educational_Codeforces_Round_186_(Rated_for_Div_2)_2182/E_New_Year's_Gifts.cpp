#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<int> a(m); for(int &i : a) cin >> i;
    vector<pair<ll, ll>> cx(n);

    for(int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        cx[i] = {x, z-y}; k -= y;
    }

    sort(cx.begin(), cx.end());
    sort(a.begin(), a.end());

    int ans = 0;
    int l = 0;
    set<pair<ll, int>> cont;
    vector<bool> happy(n);
    for(int i = 0; i < m; i++) {
        while(l < n && cx[l].first <= a[i]) {cont.insert({cx[l].second, l}); l++;}
        if(cont.size()) {
            //match box
            auto it = prev(cont.end());
            happy[it->second] = true;
            // cout << it->first << endl;
            ans++;
            cont.erase(it);
        }
    }

    // for(int i = 0; i < n; i++) if(happy[i]) cout << i << endl;
    vector<int> fin;
    for(int i = 0; i < n; i++) {
        if(!happy[i]) fin.push_back(cx[i].second);
    }

    sort(fin.begin(), fin.end());

    for(int i = 0; i < fin.size(); i++) {
        if(fin[i] > k) break;
        ans++;
        k -= fin[i];
    }

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