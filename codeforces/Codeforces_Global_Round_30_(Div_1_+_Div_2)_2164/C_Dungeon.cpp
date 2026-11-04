#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;

    multiset<int> a;
    vector<int> b(m), c(m);
    multiset<pair<int, int>> bc;

    for(int i = 0; i < n; i++) {int x; cin >> x; a.insert(x);}
    for(int i = 0; i < m; i++) {cin >> b[i];}
    for(int i = 0; i < m; i++) {cin >> c[i];}
    vector<int> latter;
    for(int i= 0; i < m; i++)
        if(!c[i]) latter.push_back({b[i]});
        else bc.insert({b[i], c[i]});

    int ans = 0;

    // for(auto x : c) cout << x << " ";
    // cout << endl;

    while(bc.size()) {

        pair<int, int> xx = *bc.begin();
        auto it = a.lower_bound(xx.first);
        if(it == a.end()) break;

        int sw = max(*it, xx.second);

        bc.erase(bc.begin());
        a.erase(it); a.insert(sw);
        ans++;

    }

    sort(latter.begin(), latter.end());

    // for(int x : a) cout << x << " ";
    // cout << endl;

    // for(int x : latter) cout << x << " ";
    // cout << endl;

    for(int x : latter) {
        auto it = a.lower_bound(x);
        if(it == a.end()) break;
        a.erase(it);
        ans++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}