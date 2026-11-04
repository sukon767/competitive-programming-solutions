#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()

int N;
vector<pair<int, int>> z, mx;

void prop(int i) {
    for(int j = 0; j < 2; j++) {
        mx[i<<1|j] = max(mx[i<<1|j], z[i]);
        z[i<<1|j] = max(z[i<<1|j], z[i]);
    }
    z[i] = {0, -1};
}

void upd(pair<int, int> v, int p, int q, int i = 1, int l = 0, int r = N-1) {
    if(p <= l && r <= q) {mx[i] = max(mx[i], v); z[i] = max(z[i], v); return;}
    
    prop(i);

    int m = (l+r)>>1;
    if(p <= m) upd(v, p, q, i<<1, l, m);
    if(m+1 <= q) upd(v, p, q, i<<1|1, m+1, r);

    mx[i] = max(mx[i<<1], mx[i<<1|1]);
}

pair<int, int> query(int p, int q, int i = 1, int l = 0, int r = N-1) {
    if(p <= l && r <= q) return mx[i];

    //prop
    prop(i);

    int m = (l+r)>>1;
    pair<int, int> ans = {0, -1};
    if(p <= m) ans = max(ans, query(p, q, i<<1, l, m));
    if(m+1 <= q) ans = max(ans, query(p, q, i<<1|1, m+1, r));

    return ans;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> cmp;
    vector<vector<pair<int, int>>> ranges(n);

    for(int i = 0; i < m; i++) {
        int j, l, r; cin >> j >> l >> r; 
        ranges[--j].push_back({--l, --r});
    }

    for(auto &v : ranges) {
        sort(v.begin(), v.end());
        vector<pair<int, int>> v2;
        for(int i = 0; i < sz(v); i++) {
            if(sz(v2) && v[i].first <= v2.back().second) {
                v2.back().second = max(v2.back().second, v[i].second);
            } else v2.push_back(v[i]);
        }
        v = v2;
        for(auto& p : v) {cmp.push_back(p.first); cmp.push_back(p.second);} 
    }

    sort(cmp.begin(), cmp.end()); cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    map<int, int> comp; for(int i = 0; i < sz(cmp); i++) comp[cmp[i]] = i;
    
    for(auto& v : ranges)
        for(auto& p : v) p = {comp[p.first], comp[p.second]};

    vector<pair<int, int>> dp(n, {0, -1});
    N = sz(cmp);
    z = mx = vector<pair<int, int>>(4*N, {0, -1});

    int lst = 0;


    for(int i = 0; i < n; i++) {
        // cout << i << endl;
        pair<int, int> bst = {0, -1};
        for(auto& [l, r] : ranges[i]) {
            bst = max(bst, query(l, r));
            // cout << l << " " << r << endl;
        }
        dp[i] = {1+bst.first, bst.second};
        // cout << i << " " << dp[i].first << " " << dp[i].second << endl;

        for(auto& [l, r] : ranges[i]) {
            upd({dp[i].first, i}, l, r);
            // cout << l << " " << r << endl;
        }
        if(dp[i].first > dp[lst].first) lst = i;
    }

    
    int num = n-1;
    vector<bool> on(n);
    on[lst] = true;
    while(dp[lst].second > -1) {
        lst = dp[lst].second; on[lst] = true; num--;
    }

    cout << num << "\n";
    for(int i = 0; i < n; i++) {
        if(!on[i]) {cout << i+1 << " ";}
    }
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