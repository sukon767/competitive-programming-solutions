#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    vector<pair<int, int>> th;
    int ans = INT_MAX;

    for(int x : a) {
        if(x == 1) {
            th.push_back({1, 0});
            th.push_back({2, 1});
            continue;
        }

        int op = 0;
        while(x > 1) {
            th.push_back({x, op});
            if(x%2) x++;
            else x>>=1;
            op++;
        }

        th.push_back({1, op});
    }

    //disaster?
    sort(th.begin(), th.end());



    int on = -1, cur = 0, ops = 0;
    for(int i = 0; i < sz(th); i++) {
        if(th[i].first != on) {
            on = th[i].first; cur = 1; ops = th[i].second;
        } else {cur++; ops += th[i].second;}
        if(cur == n) ans = min(ans, ops);
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */