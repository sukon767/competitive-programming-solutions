#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
int N;
vector<int> mn;
void upd(int k, int v, int i = 1, int l = 0, int r = N-1) {
    if(l == r) {mn[i] = v; return;}
    int m = (l+r)>>1;
    if(k <= m) upd(k, v, i<<1, l, m);
    if(m+1 <= k) upd(k, v, i<<1|1, m+1, r);
    mn[i] = min(mn[i<<1], mn[i<<1|1]);
}
int query(int p, int q, int i = 1, int l = 0, int r = N-1) {
    if(p <= l && r <= q) return mn[i];
    int m = (l+r)>>1;
    int ans = INT_MAX;
    if(p <= m) ans = min(ans, query(p, q, i<<1, l, m));
    if(m+1 <= q) ans = min(ans, query(p, q, i<<1|1, m+1, r));
    return ans;
}
void solve() {
    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(int& i : x) cin >> i;
    map<int, set<int>> mp;
    N = n;
    mn = vector<int>(4*N, INT_MAX);
    for(int i = n-1; i >= 0; i--) {
        auto& v = mp[x[i]];
        if(sz(v)) {
            upd(i, *v.begin());
        }
        v.insert(i);
    }
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int k, u; cin >> k >> u;
            auto& v1 = mp[x[--k]];
            auto it = v1.erase(v1.find(k));
            if(it != v1.begin()) {
                auto pit = prev(it);
                if(it == v1.end()) {
                    upd(*pit, INT_MAX);
                } else {
                    upd(*pit, *it);
                }
            }
            x[k] = u;
            auto& v2 = mp[x[k]];
            it = v2.upper_bound(k);
            if(it != v2.begin()) {
                auto pit = prev(it);
                upd(*pit, k);
            }
            if(it != v2.end()) {
                upd(k, *it);
            } else upd(k, INT_MAX);
            v2.insert(k);
        } else {
            int a, b; cin >> a >> b;
            int y = query(--a, --b);
            if(y <= b) cout << "NO";
            else cout << "YES";
            cout << "\n";
        }
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
