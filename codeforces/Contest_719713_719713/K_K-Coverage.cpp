#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int n, L, k;
//prefix, prefix max.
vector<pair<int, int>> seg;
vector<int> cont;

void merge(pair<int, int> u, pair<int, int> v, pair<int, int> &gol) {
    gol = {u.f + v.f, max(u.s, u.f+v.s)};
}

void build(int i = 1, int l = 0, int r = 3*n-1) {
    if(l == r) {seg[i] = {cont[l], max(0, cont[l])}; return;}
    int m = (l+r)>>1;
    build(i<<1, l, m); build(i<<1|1, m+1, r);
    merge(seg[i<<1], seg[i<<1|1], seg[i]);
}

pair<int, int> query(int ql, int qr, int i = 1, int l = 0, int r = 3*n-1) {
    if(ql <= l && r <= qr) return seg[i];
    pair<int, int> ret = {0, 0};
    int m = (l+r)>>1;
    if(ql <= m) merge(ret, query(ql, qr, i<<1, l, m), ret);
    if(m+1 <= qr) merge(ret, query(ql, qr, i<<1|1, m+1, r), ret);
    return ret;
}

//sukon always reads the entire problem statement.
void solve() {
    cin >> n >> L >> k;
    seg = vector<pair<int, int>>(12*n);
    //(3*n size).
    //first we do the partial segment shits.
    //so we build it like val[i] = (a[i] == k+1) - (a[i] == k) + (a[i+L] == k-1) - (a[i+L] == k).
    //and prefix maximum from i to i+L-1.
    vector<int> val(4*n+1), neg(4*n+1), eq(4*n+1), pos(4*n+1);
    vector<int> lefts(n);
    for(int i = 0; i < n; i++) {
        cin >> lefts[i];
        val[lefts[i]]++; val[lefts[i]+L]--;
    }

    partial_sum(all(val), val.begin());
    for(int i = 0; i <= 4*n; i++) {
        eq[i] += (val[i]==k);
        neg[i] += (val[i]==k-1);
        pos[i] += (val[i]==k+1);
    }
    partial_sum(all(eq), eq.begin());
    partial_sum(all(neg), neg.begin());
    partial_sum(all(pos), pos.begin());
    int base = eq.back();
    int ans = base;

    //right shit.
    cont = vector<int>(3*n);
    for(int i = 0; i < 3*n; i++) cont[i] = (val[i]==k+1) - (val[i]==k) + (val[i+L]==k-1) - (val[i+L]==k);
    build();

    for(int l : lefts) {
        auto [_, del] = query(l, l+L-1);
        ans = max(ans, base+del);
    }

    //left shit AHHHH
    for(int i = 0; i < 3*n; i++) {
        cont[i] = (val[i+L]==k+1) - (val[i+L]==k) + (val[i]==k-1) - (val[i]==k);
    }

    //we reverse because its suffix max
    reverse(all(cont));
    build();

    for(int l : lefts) {
        if(!l) continue;
        //reverse the query PLEASE WORK
        // auto [_, del] = query(max(0, l-L), l-1);
        auto [_, del] = query(3*n-1 - (l-1), 3*n-1 - (max(0, l-L)));
        ans = max(ans, base+del);
    }

    //the triviology phase
    vector<int> pre(3*n+1), suf(3*n+1);
    for(int i = 0; i <= 3*n; i++) {
        pre[i] = (neg[i+L-1] - (i?neg[i-1]:0)) - (eq[i+L-1] - (i?eq[i-1]:0));
        if(i) pre[i] = max(pre[i], pre[i-1]);
    }
    for(int i = 3*n; i >= 0; i--) {
        suf[i] = (neg[i+L-1] - (i?neg[i-1]:0)) - (eq[i+L-1] - (i?eq[i-1]:0));
        if(i < 3*n) suf[i] = max(suf[i], suf[i+1]);
    }

    for(int l : lefts) {
        int del = 0;
        if(l >= L) del = max(del, pre[l-L]);
        del = max(del, suf[l+L]);
        ans = max(ans, base + del + (pos[l+L-1] - (l?pos[l-1]:0)) - (eq[l+L-1] - (l?eq[l-1]:0)));
    }

    cout << ans;
}

//king of the sun o_O
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