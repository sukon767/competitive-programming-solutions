#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

vector<vector<ll>> adj;
vector<ll> a, s;
vector<bool> visited;
vector<ll> ans, pre, npre;

void dfs(ll x) {
    vector<pair<ll, ll>> ms;

    for(ll y : adj[x]) {
        if(visited[y]) continue;
        visited[y] = true;
        dfs(y);
        s[x] = max(s[x], s[y]+1);
        pre[x] += pre[y] + a[y];
        npre[x] += npre[y] + pre[y] + a[y];
        ms.push_back({s[y]+1, y});
    }
    if(!ms.size()) return;
    // cout << x << " " << ms.size() << endl;
    if(ms.size() == 1) {ll y = ms[0].second; ans[x] = ans[y] + pre[y] + a[y]; return;}

    sort(ms.begin(), ms.end()); reverse(ms.begin(), ms.end());

    ans[x] = npre[x] + (pre[ms[0].second]+a[ms[0].second])*ms[1].first;

    // cout << x << endl;
    // for(auto p : ms) cout << p.first << " " << p.second << endl;

    // cout << x << " cont1 " << (pre[ms[0].second]+a[ms[0].second])*ms[1].first << " " << ms[1].first << " " << s[ms[1].second] << endl;
    for(ll i = 1; i < ms.size(); i++) {
        ll t = ans[x];
        ans[x] = max(ans[x], npre[x] + (pre[ms[i].second]+a[ms[i].second])*ms[0].first);
        // if(ans[x] > t) cout << x << " " << "win1" << endl;
    }
    
    for(ll i = 0; i < ms.size(); i++) {
        ll t = ans[x];
        ans[x] = max(ans[x], npre[x] + ans[ms[i].second] - npre[ms[i].second]);
        // if(ans[x] > t) cout << x << " " << "win2" << endl;
    }

}
 
void solve() {
    ll n; cin >> n;
    ans = vector<ll>(n), pre = vector<ll>(n), npre = vector<ll>(n);
    a = vector<ll>(n), s = vector<ll>(n);
    adj = vector<vector<ll>>(n);
    visited = vector<bool>(n);
    for(ll &i : a) cin >> i;
    for(ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v;
        adj[--u].push_back(--v); adj[v].push_back(u);
    }

    visited[0] = true; dfs(0);

    // for(ll i = 0; i < n; i++) cout << a[i] << " ";
    // cout << endl;
    // for(ll i = 0; i < n; i++) cout << pre[i] << " ";
    // cout << endl;
    // for(ll i = 0; i < n; i++) cout << npre[i] << " ";
    // cout << endl;
    for(ll i = 0; i < n; i++) cout << ans[i] << " ";
    // cout << endl;
    
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}