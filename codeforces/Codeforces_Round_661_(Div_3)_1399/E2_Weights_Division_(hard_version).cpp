#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<bool> vis;
vector<vector<vector<int>>> adj;
vector<int> cnt;
vector<vector<ll>> edge; //weight, cnt, cost

void dfs(int x) {
    // cout << x+1 << endl;
    vis[x] = true;
    for(auto& v : adj[x]) {
        if(vis[v[0]]) continue;
        dfs(v[0]);
        edge.push_back({v[1], cnt[v[0]], v[2]});
        cnt[x] += cnt[v[0]];
    }

    if(sz(adj[x]) == 1) cnt[x] = 1;
}

void solve() {
    int n; cin >> n;
    ll S; cin >> S;
    vis = vector<bool>(n);
    adj = vector<vector<vector<int>>>(n);
    cnt = vector<int>(n);
    edge.clear();

    for(int i = 0; i < n-1; i++) {
        int u, v, w, c; cin >> u >> v >> w >> c;
        adj[--u].push_back({--v, w, c}); adj[v].push_back({u, w, c});
    }

    dfs(0);

    auto cmp = [](const pair<ll, ll>& a, const pair<ll, ll>& b) {return (a.first-a.first/2)*a.second < (b.first-b.first/2)*b.second;};

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq1(cmp), pq2(cmp);

    
    vector<ll> c1, c2;
    ll x1 = 0, x2 = 0;

    // cout << sz(edge) << endl;
    
    for(int i = 0; i < n-1; i++) {
        if(edge[i][2] == 1) {
            pq1.push({edge[i][0], edge[i][1]});
            x1 += edge[i][0]*edge[i][1];
        } else {
            pq2.push({edge[i][0], edge[i][1]});
            x2 += edge[i][0]*edge[i][1];
        }
    }
    
    c1 = {x1}, c2 = {x2};
    
    while(sz(pq1)) {
        auto p = pq1.top(); pq1.pop();
        x1 += ((p.first>>1)-p.first)*p.second;
        c1.push_back(x1);
        if(p.first>>1) pq1.push({p.first>>1, p.second});
    }

    // cout << "aDSF" << endl;

    while(sz(pq2)) {
        auto p = pq2.top(); pq2.pop();
        x2 += ((p.first>>1)-p.first)*p.second;
        c2.push_back(x2);
        if(p.first>>1) pq2.push({p.first>>1, p.second});
    }

    // for(ll x : c1) cout << x << " ";
    // cout << endl;
    // for(ll x : c2) cout << x << " ";
    // cout << endl;

    int ans = INT_MAX;

    int r = sz(c2)-1;
    int l = 0;
    while(l < sz(c1) && c1[l]>S) l++;

    for(int i = l; i < sz(c1); i++) {
        while(r && c1[i]+c2[r-1]<=S) r--;
        ans = min(ans, i + 2*r);
        // cout << i << " " << r << endl;
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