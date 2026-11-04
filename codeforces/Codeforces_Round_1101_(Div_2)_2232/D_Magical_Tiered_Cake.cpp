#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    for(int i = 0; i < n; i++) if(a[i] > i) {
        cout << "NO"; return;
    }
    vector<vector<int>> ans;
    auto f = [&](auto&& self, int i, int j, int o, int n) -> void {
        if(n == 0) return;
        self(self, i, o, j, n-1-a[n-1]);
        ans.push_back({n, i, j});
        if(a[n-1] == 0) self(self, o, j, i, n-1);
        else {
            self(self, o, i, j, n-1-a[n-1]);
            self(self, i, j, o, n-1);
        }
    };
    f(f, 1, 3, 2, n);
    cout << "YES\n" << sz(ans) << "\n";
    for(auto& v : ans) {for(auto& i : v) cout << i << " "; cout << "\n";}
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