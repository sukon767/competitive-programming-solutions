#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int n;
struct Node {
    int ans = 0, mn = 0, mx = 0;
};
vector<Node> seg; //ans, min, max.
vector<int> a;

void comb(int i, int hb) {
    if(seg[i<<1].mx > seg[i<<1|1].mn) {
        seg[i].ans = hb+1;
    } else seg[i].ans = max(seg[i<<1].ans, seg[i<<1|1].ans);
    seg[i].mn = min(seg[i<<1].mn, seg[i<<1|1].mn);
    seg[i].mx = max(seg[i<<1].mx, seg[i<<1|1].mx);
}

void build(int i = 1, int l = 0, int r = n-1) {
    if(l==r) {
        seg[i] = {0, a[l], a[l]};
        return;
    }
    int hb = 31 - __builtin_clz((r-l+1));
    if((r-l+1) == (1<<hb)) hb--;
    
    build(i<<1, l, l+(1<<hb)-1);
    build(i<<1|1, l+(1<<hb), r);
    
    comb(i, hb);
}

void upd(int ij, int xj, int i = 1, int l = 0, int r = n-1) {
    if(l==r) {
        seg[i] = {0, xj, xj};
        return;
    }
    int hb = 31 - __builtin_clz((r-l+1));
    if((r-l+1) == (1<<hb)) hb--;
    
    if(ij < l+(1<<hb)) upd(ij, xj, i<<1, l, l+(1<<hb)-1);
    else upd(ij, xj, i<<1|1, l+(1<<hb), r);
    
    comb(i, hb);
}

//sukon always reads the entire problem statement.
void solve() {
    int q; cin >> n >> q;
    seg.resize(4*n, Node());
    a.resize(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        upd(i, a[i]);
    }
    build();

    for(int b = 0; b <= q; b++) {
        if(b) {
            //upd
            int ij, xj; cin >> ij >> xj;
            upd(ij, xj);
        }
        cout << (seg[1].ans==0?0:(1<<(seg[1].ans-1))) << "\n";
    }
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