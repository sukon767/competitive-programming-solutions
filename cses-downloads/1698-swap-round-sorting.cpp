#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) {cin >> i; i--;}
    vector<bool> vis(n);
    vector<vector<int>> cyc;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        int j = i;
        cyc.push_back({});
        while(!vis[j]) {
            vis[j] = true;
            cyc.back().push_back(j);
            j = a[j];
        }
    }
    int cnt = 0;
    pair<vector<pair<int, int>>, vector<pair<int, int>>> ans;
    for(auto& v : cyc) {
        if(sz(v) == 2) {
            cnt = max(cnt, 1);
            ans.first.push_back({v[0], v[1]});
        } else if(sz(v) > 2) {
            cnt = max(cnt, 2);
            for(int j = 0; 1+j < sz(v)-1-j; j++) {
                ans.first.push_back({v[1+j], v[sz(v)-1-j]});
            }
            ans.second.push_back({v[0], v[1]});
            for(int j = 0; 2+j < sz(v)-1-j; j++) ans.second.push_back({v[2+j], v[sz(v)-1-j]});
        }
    }
    if(cnt == 2) {
        cout << "2\n";
    } else if(cnt == 1) cout << "1\n";
    else {cout << "0\n"; return;}
    cout << sz(ans.first) << "\n";
    for(auto& p : ans.first) cout << p.first+1 << " " << p.second+1 << "\n";
    if(cnt == 2) {
        cout << sz(ans.second) << "\n";
        for(auto& p : ans.second) cout << p.first+1 << " " << p.second+1 << "\n";
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
