#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

int n, k; int l2 = 20;
vector<vector<int>> mn;

int rmq(int l, int r) { // [l; r)
    int t = __lg(r - l);
    return min(mn[t][l], mn[t][r - (1 << t)]);
}

vector<vector<int>> seg;
int mi;

void build(int i, int l, int r) {
    int m = (l+r)>>1;
    int y = l, z = m;
    for(int j = 2; j < 4; j++) {
        if(seg[i][j]!=-1) continue;
        int re;
        // cout << i << " " << l << " " << r << " " << j << endl;
        // cout << y << " " << z << endl;
        if(z-y+1 >= n) re = mi;
        else if(y%n <= z%n) re = rmq(y%n, z%n+1);
        else re = min(rmq(y%n, n), rmq(0, z%n+1));
        seg[i][j]=sz(seg);
        seg.push_back({re, 0, -1, -1});
        y = m+1, z = r;
    }
}

void prop(int i) {
    if(seg[i][1]) {
        int a = seg[i][2], b = seg[i][3];
        seg[a][0] = seg[a][1] = seg[b][0] = seg[b][1] = seg[i][1];
        seg[i][1] = 0;
    }
}

void upd(int p, int q, int x, int i = 1, int l = 0, int r = n*k-1) {
    if(p <= l && r <= q) {seg[i] = {x, x, seg[i][2], seg[i][3]}; return;}
    build(i, l, r);
    // cout << p << " " << q << " " << x << " " << i << " " << l << " " << r << endl;
    prop(i);
    int m = (l+r)>>1;
    if(p <= m) upd(p, q, x, seg[i][2], l, m);
    if(m+1 <= q) upd(p, q, x, seg[i][3], m+1, r);
    seg[i][0] = min(seg[seg[i][2]][0], seg[seg[i][3]][0]);
}

int query(int p, int q, int i = 1, int l = 0, int r = n*k-1) {
    if(p <= l && r <= q) return seg[i][0];
    build(i, l, r);
    prop(i);
    int m = (l+r)>>1;
    int ans = INT_MAX;
    if(p <= m) ans = min(ans, query(p, q, seg[i][2], l, m));
    if(m+1 <= q) ans = min(ans, query(p, q, seg[i][3], m+1, r));
    return ans;
}

void solve() {
    cin >> n >> k;
    mn = vector<vector<int>>(l2, vector<int>(n));
    for(int &i : mn[0]) cin >> i;

    for(int l = 0; l < l2 - 1; l++)
        for(int i = 0; i + (2 << l) <= n; i++)
            mn[l+1][i] = min(mn[l][i], mn[l][i + (1 << l)]);

    mi = *min_element(mn[0].begin(), mn[0].end());
    seg = {{}, {mi, 0, -1, -1}};
    
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int t, l, r; cin >> t >> l >> r; l--; r--;
        if(t==1) {
            int x; cin >> x;
            upd(l, r, x);
        } else cout << query(l, r) << "\n";
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