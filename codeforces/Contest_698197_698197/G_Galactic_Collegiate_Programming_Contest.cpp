#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> cur(n);
    ordered_set<pair<pair<int,int>, int>> ss;

    for(int i = 0; i < n; i++) ss.insert({{0, 0}, i});
    for(int i = 0; i < m; i++) {
        int t, p; cin >> t >> p; t--;
        ss.erase({{cur[t].first, cur[t].second}, t});
        cur[t].first++; cur[t].second -= p;
        ss.insert({{cur[t].first, cur[t].second}, t});

        int lb = ss.order_of_key({{cur[0].first, cur[0].second}, INT_MAX});
        cout << n+1-lb << "\n";
    }
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