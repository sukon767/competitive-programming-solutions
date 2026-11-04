#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> b(n); for(int &i : b) cin >> i;

    for(int i = 0; i < m; i++) {
        int s, t, w; cin >> s >> t >> w;
        adj[--t].push_back({--s, w});
    }

    int lo = 0, hi = 1e9+1;
    vector<int> ans(n);
    while(lo < hi) {

        int mid = (lo+hi)/2;
        ans.assign(n, -1);
        ans[0] = min(mid, b[0]);

        for(int i = 1; i < n; i++) {
            for(auto p : adj[i]) {
                int s = p.first, w = p.second;
                if(ans[s] < w) continue;
                ans[i] = max(ans[i], min(mid, ans[s]+b[i]));
            }
        }
        if(ans.back() == -1) lo = mid+1;
        else hi = mid;
    }

    if(lo == 1e9+1) cout << -1;
    else cout << lo;
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