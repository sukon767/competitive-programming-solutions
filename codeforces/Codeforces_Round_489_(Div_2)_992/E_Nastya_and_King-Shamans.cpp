#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int n;
vector<ll> z, seg, init;


void push(int i) {
    seg[i<<1] += z[i]; seg[i<<1|1] += z[i];
    z[i<<1] += z[i]; z[i<<1|1] += z[i]; z[i] = 0;
}

void upd(int i) {
    seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

void build(int i = 1, int l = 0, int r = n-1) {
    if(l == r) {seg[i] = init[l]; return;}
    int m = (l+r)>>1;
    build(i<<1, l, m); build(i<<1|1, m+1, r);
    upd(i);
}

void modify(int ql, int qr, ll v, int i = 1, int l = 0, int r = n-1) {
    if(ql <= l && r <= qr) {seg[i] += v; z[i] += v; return;}
    push(i);
    int m = (l+r)>>1;
    if(ql <= m) modify(ql, qr, v, i<<1, l, m);
    if(m+1 <= qr) modify(ql, qr, v, i<<1|1, m+1, r);
    upd(i);
}

int query(int i = 1, int l = 0, int r = n-1) {
    if(l == r) {return seg[i] == 0 ? l : -2;}
    push(i);
    int ans = -2;
    int m = (l+r)>>1;
    if(seg[i<<1] == 0) return query(i<<1, l, m);
    if(seg[i<<1] >= 0) ans = max(ans, query(i<<1, l, m));
    if(seg[i<<1|1] >= 0) ans = max(ans, query(i<<1|1, m+1, r));
    return ans;
}

//sukon always reads the entire problem statement.
void solve() {
    int q; cin >> n >> q;
    z = seg = vector<ll>(4*n);
    init = vector<ll>(n);
    vector<ll> a(n);
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        init[i] = a[i] - tot;
        tot += a[i];
    }
    build();

    while(q--) {
        int pi; ll xi; cin >> pi >> xi;
        ll del = xi - a[--pi];
        modify(pi, pi, del);
        if(pi+1 < n) modify(pi+1, n-1, -del);
        cout << query()+1 << "\n";
        a[pi] = xi;
    }
}

//king of the sun o_O
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