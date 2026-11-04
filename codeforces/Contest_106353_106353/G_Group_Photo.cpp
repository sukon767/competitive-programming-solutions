#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int n;
vector<int> seg;
void upd(int k, int v, int i = 1, int l = 0, int r = n) {
    if(l==r) {seg[i] = max(seg[i], v); return;}
    int m = (l+r)>>1;
    if(k <= m) upd(k, v, i<<1, l, m);
    else upd(k, v, i<<1|1, m+1, r);
    seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

int query(int ql, int qr, int i = 1, int l = 0, int r = n) {
    if(ql <= l && r <= qr) {return seg[i];}
    int m = (l+r)>>1;
    if(qr <= m) return query(ql, qr, i<<1, l, m);
    if(m+1 <= ql) return query(ql, qr, i<<1|1, m+1, r);
    return max(query(ql, qr, i<<1, l, m), query(ql, qr, i<<1|1, m+1, r));
}

//sukon always reads the entire problem statement.
void solve() {
    cin >> n; seg = vector<int>(4*(n+1));
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<array<int, 3>> arrow;
    for(int i = 0; i < n; i++) {
        //downs
        if(a[i] >= i+1) arrow.push_back({i+1, 0, -(a[i]-(i+1))});
        //rights
        if(a[i] >= n-i) arrow.push_back({(a[i] - (n-i)), 1, n-i});
    }
    sort(all(arrow));
    for(auto &v : arrow) {
        int j = (v[1] ? v[2] : -v[2]);
        upd(j, 1 + query(0, j-v[1]));
    }
    cout << n-query(0, n);
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