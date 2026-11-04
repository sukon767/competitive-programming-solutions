#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

int maxN = 1e6;
vector<vector<int>> fac(maxN+1);
vector<vector<int>> ind(maxN+1);
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int &i : a) cin >> i;

    vector<int> ps;
    for(int i = 0; i < n; i++) {
        for(int d : fac[a[i]]) {
            ind[d].push_back(i+n-1);
            if(i) ind[d].push_back(i-1);
            ps.push_back(d);
        }
    }

    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

    vector<int> par(2*n-1, -1);
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    };
    
    for(int i : ps) {
        sort(ind[i].begin(), ind[i].end());
        for(int j = 0; j+1 < ind[i].size(); j++) {
            if(ind[i][j+1] - ind[i][j] <= k) unite(ind[i][j+1], ind[i][j]);
        }
    }

    ll ans = 0;
    for(int i = 0; i < 2*n-1; i++) {
        if(par[i] < 0) ans++;
        // cout << i << " " << par[i] << endl;
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            ans += n-2;
            if(!i) ans++;
        }
    }

    for(int p : ps) ind[p].clear();

    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 2; i <= maxN; i++) {
        if(!fac[i].size()) {
            for(int j = i; j <= maxN; j+=i) fac[j].push_back(i);
        }
    }

    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}