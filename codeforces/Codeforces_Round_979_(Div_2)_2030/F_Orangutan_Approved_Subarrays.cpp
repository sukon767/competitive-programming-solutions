#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//rmq
int n;
vector<int> seg;

void upd(int k, int u, int i = 1, int l = 0, int r = n-1) {
    if(l==r) {seg[i] = u; return;}
    int m = (l+r)>>1;
    if(k <= m) upd(k, u, i<<1, l, m);
    else upd(k, u, i<<1|1, m+1, r);
    seg[i] = min(seg[i<<1], seg[i<<1|1]);
}

int query(int p, int q, int i = 1, int l = 0, int r = n-1) {
    if(p <= l && r <= q) return seg[i];
    int ans = n;
    int m = (l+r)>>1;
    if(p <= m) ans = min(ans, query(p, q, i<<1, l, m));
    if(m+1 <= q) ans = min(ans, query(p, q, i<<1|1, m+1, r));
    return ans;
}

void solve() {
    int q; cin >> n >> q;
    vector<int> a(n); for(int& i : a) {cin >> i; i--;}

    vector<int> lst(n, -1), bad(n, n), lind(n, -1);
    for(int i = 0; i < n; i++) {
        lind[i] = lst[a[i]];
        lst[a[i]] = i;
    }

    seg = vector<int>(4*n, n);

    for(int i = n-1; i >= 0; i--) {
        if(lind[i] == -1 || lind[i]+1 > i-1) continue;
        int mn = query(lind[i]+1, i-1);
        bad[lind[i]] = min(bad[lind[i]], mn);
        upd(lind[i], i);
    }

    for(int i = n-2; i >= 0; i--) bad[i] = min(bad[i], bad[i+1]);

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        if(bad[--l] <= --r) cout << "NO";
        else cout << "YES";
        cout << "\n";
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