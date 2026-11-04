#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) {cin >> i;}
    int ans = 0;
    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    int on = 1, prev = -1;
    while(bfs.size()) {
        auto p = bfs.front(); bfs.pop();
        ans = p.second;
        while(on < n && a[on] > prev) {
            bfs.push({a[on], p.second+1});
            prev = a[on];
            on++;
        }
        prev = -1;
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