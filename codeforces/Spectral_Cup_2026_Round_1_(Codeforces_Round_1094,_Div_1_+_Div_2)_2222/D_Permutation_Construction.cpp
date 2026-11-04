#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    vector<ll> pre(n);
    pre[0] = a[0]; for(int i = 1; i < n; i++) pre[i] = pre[i-1] + a[i];

    set<pair<ll, int>> sf;
    sf.insert({0LL, 0});
    vector<vector<int>> adj(n);
    vector<int> in(n);

    for(int i = 0; i < n-1; i++) {
        if(a[i] >= 0) {
            adj[i+1].push_back(i);
            in[i]++;
            // cout << i+1 << " " << i << endl;
        } else {
            adj[i].push_back(i+1);
            in[i+1]++;
            // cout << i << " " << i+1 << endl;
        }

        auto it = sf.upper_bound({pre[i], INT_MAX});
        if(it != sf.end()) {
            if(abs(it->second - (i+1)) != 1) {
                adj[it->second].push_back(i+1);
                in[i+1]++;
                // cout << "VAL: " << pre[i] << " " << it->first << endl;
                // cout << it->second << " " << i+1 << endl;
            }   
        }
        if(it != sf.begin()) {
            it = prev(it);

            if(abs(it->second - (i+1)) != 1) {
                adj[i+1].push_back(it->second);
                in[it->second]++;
                // cout << i+1 << " " << it->second << endl;
            }
        }

        sf.insert({pre[i], i+1});
    }

    vector<int> ord;
    queue<int> bfs;
    for(int i = 0; i < n; i++) {
        if(!in[i]) bfs.push(i);
    }

    int left = n;

    while(sz(bfs)) {
        int x = bfs.front(); bfs.pop();
        ord.push_back(x);
        left--;
        for(int y : adj[x]) {
            in[y]--;
            if(!in[y]) bfs.push(y);
        }
    }

    assert(!left);

    // for(int x : ord) cout << x << " ";
    // cout << endl;

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[ord[i]] = i+1;
    }

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