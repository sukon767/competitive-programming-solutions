#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
vector<vector<pair<int, ll>>> adj;
vector<pair<int, ll>> imb;
ll maxm = 1e18;
 
//v is "virtual" node?
void dfs(int x, ll r, ll mod, int v, ll offset) {

    // cout << x+1 << " " << r << " " << mod << " " << v+1 << " " << offset << endl;
 
    if(!sz(adj[x])) {
        imb[v] = {x, 0};
        return;
    }
    if(mod == -1) {
        auto& [y, w] = adj[x][r%sz(adj[x])];
        dfs(y, r + w, -1, v, 0);
        return;
    }
 
    ll ad = sz(adj[x]);
    ad /= gcd(ad, mod);
 
    if(ad == 1) {
        auto& [y, w] = adj[x][r%sz(adj[x])];
        dfs(y, r+w, mod, v, offset + w);
    } else if(ad <= maxm/mod) {
        imb[v] = {x, offset};

        for(int i = 0; i < ad; i++) {
            auto& [y, w] = adj[x][(r+i*mod)%sz(adj[x])];
            dfs(y, r + i*mod + w, mod*ad, y, 0);
        }
    } else {
        //exit!
        imb[v] = {x, offset};

        for(int i = 0; i < maxm/mod; i++) {
            auto& [y, w] = adj[x][(r+i*mod)%sz(adj[x])];
            dfs(y, r + i*mod + w, -1, y, 0);
        }
    }
}
 
void solve() {
    int n, q; cin >> n >> q;
    vector<ll> f(n-1), l(n-1);
    for(ll& i : f) {cin >> i; i--;}
    for(ll& i : l) cin >> i;
 
    adj = vector<vector<pair<int, ll>>>(n);
    imb = vector<pair<int, ll>>(n);
    for(int i = 0; i < n; i++) imb[i].first = i;
    
    for(int i = 0; i < n-1; i++) {
        adj[f[i]].push_back({i+1, l[i]});
    }
 
    dfs(0, 0, 1, 0, 0);
 
    for(int i = 0; i < q; i++) {
        ll m; cin >> m;
        int on = 0;
        while(true) {
            if(on != imb[on].first) {
                m += imb[on].second;
                on = imb[on].first;
            }
            if(!sz(adj[on])) break;

            auto& [y, w] = adj[on][m%sz(adj[on])];
            on = y;
            m += w;
        }
        cout << on+1 << " ";
    }
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