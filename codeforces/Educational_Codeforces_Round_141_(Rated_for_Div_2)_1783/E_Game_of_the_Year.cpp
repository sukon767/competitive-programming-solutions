#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> ab(n);
    for(auto &p : ab) cin >> p.first;
    for(auto &p : ab) cin >> p.second;
    vector<int> pre(n+1);
    for(int i = 0; i < n; i++) {
        auto& [a, b] = ab[i];
        if(a >= b) {
            pre[b]++;
            if(a <= n) pre[a]--;
        }
    }
    vector<int> ans;
    for(int i = 2; i <= n; i++) pre[i]+=pre[i-1];
    for(int k = 1; k <= n; k++) {
        bool ok = true;
        for(int j = k; j <= n; j+=k) if(pre[j]) {ok=0; break;}
        if(ok) ans.push_back(k);
    }
    cout << sz(ans) << "\n";
    for(int x : ans) cout << x << " ";
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