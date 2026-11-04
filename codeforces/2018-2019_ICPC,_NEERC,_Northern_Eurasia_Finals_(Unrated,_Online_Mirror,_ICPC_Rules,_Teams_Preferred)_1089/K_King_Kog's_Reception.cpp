#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

int n = 1e6;
vector<pair<ll, ll>> seg(4*n); //prefix sum, minimum.

void merge(int i) {
    seg[i].first = seg[i<<1].first+seg[i<<1|1].first;
    seg[i].second = min(seg[i<<1].second, seg[i<<1].first+seg[i<<1|1].second);
}

void build(int i = 1, int l = 0, int r = n-1) {
    if(l==r) {seg[i]={-1, -1}; return;}
    int m = (l+r)>>1;
    build(i<<1, l, m); build(i<<1|1, m+1, r);
    merge(i);
}

pair<ll, ll> pre(int p, int i = 1, int l = 0, int r = n-1) {
    if(l==r) {return seg[i];}
    int m = (l+r)>>1;
    if(p <= m) return pre(p, i<<1, l, m);
    else {
        pair<ll, ll> t = pre(p, i<<1|1, m+1, r);
        return {seg[i<<1].first+t.first, min(seg[i<<1].second, seg[i<<1].first+t.second)};
    }
}

void upd(int k, int u, int i = 1, int l = 0, int r = n-1) {
    if(l==r) {seg[i] = {u, min(-1, u)}; return;}
    int m = (l+r)>>1;
    if(k <= m) upd(k, u, i<<1, l, m);
    else upd(k, u, i<<1|1, m+1, r);
    merge(i);
}

void solve() {
    int q; cin >> q;
    vector<int> eve(q);
    build();
    for(int tc = 0; tc < q; tc++) {
        char c; cin >> c;
        if(c=='+') {
            int t, d; cin >> t >> d;
            upd(--t, --d);
            eve[tc]=t;
        } else if(c=='-') {
            int i; cin >> i;
            upd(eve[--i], -1);
        } else {
            int t; cin >> t;
            pair<ll, ll> que = pre(--t);
            cout << que.first - que.second << "\n";
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