#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> vis(n, 0);
    vector<int> a(n-1);
    for(int &i : a) {cin >> i; i--;}

    vector<pair<int, int>> ans;
    int par = a[0]; vis[a[0]] = 2;
    int on = n-1;
    while(on >= 0 && vis[on]) {on--;}
    if(on) vis[on] = 1;
    for(int i = 1; i < n-1; i++) {
        if(vis[a[i]]) {
            // if(on == -1) {cout << -1; return;}
            ans.push_back({par, on}); vis[on] = 2;
            while(on >= 0 && vis[on]) {on--;}
            if(on) vis[on] = 1;
            // if(!vis[a[i]]) {cout << -1; return;}
        } else {
            ans.push_back({par, a[i]});
            vis[a[i]] = 2;
        }
        par = a[i];
    }
    // for(int i = 0; i < n; i++) {
    //     cout << i+1 << ' ' << vis[i] << endl;
    // }

    while(on >= 0 && vis[on]==2) {on--;}
    ans.push_back({par, on});
    cout << a[0]+1 << "\n";
    for(auto &p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
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