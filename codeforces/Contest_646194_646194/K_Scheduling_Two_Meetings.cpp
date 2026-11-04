#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> dp(1<<m, {-1, 0});
    vector<int> occ(1<<m, INT_MAX);

    vector<int> cc;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int x = 0;
        for(int j = 0; j < m; j++) if(s[j] == 'Y') x |= (1<<j);
        if(x == ((1<<m) -1)) cc.push_back(i);
        occ[x] = min(occ[x], i);
    }

    if(sz(cc) >= 2) {
        cout << cc[0]+1 << " " << cc[1]+1;
        return;
    }

    // for(int i = 0; i < 1<<m; i++) cout << i << " " << occ[i] << endl;

    for(int i = (1<<m)-1; i >= 0; i--) {
        if(occ[i] != INT_MAX) dp[i] = max(dp[i], {__builtin_popcount(i), -occ[i]});
        for(int b = 0; b < m; b++) {
            if(i>>b&1) {
                dp[i^(1<<b)] = max(dp[i^(1<<b)], dp[i]);
            }
        }
    }

    // for(int i = 0; i < 1<<m; i++) cout << i << " " << dp[i].f << endl;

    pair<int, pair<int, int>> ans = {-1, {0, 0}};
    for(int i = 0; i < (1<<m) -1; i++) {
        if(occ[i] == INT_MAX) continue;
        int xi = i^((1<<m) -1);
        ans = max(ans, {dp[xi].f - __builtin_popcount(xi), {max(-occ[i], dp[xi].s), min(-occ[i], dp[xi].s)}});
    }

    if(ans.f == -1) cout << "No";
    else cout << -ans.s.f+1 << " " << -ans.s.s+1;
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