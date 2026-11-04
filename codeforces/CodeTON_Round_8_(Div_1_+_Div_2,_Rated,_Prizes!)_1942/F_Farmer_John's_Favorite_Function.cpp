#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<pair<ll, ll>> seg;
vector<ll> a;
int n;
const int L = 10;
const ll oo = 2e18;

ll isqrt(ll x) {
    ll lo = 0, hi = 3e9;
    while(lo < hi) {
        ll m = (lo+hi+1)>>1;
        if(m*m <= x) lo = m;
        else hi = m-1;
    }
    return lo;
}

void upd(int k, ll x, int i = 1, int l = 0, int r = n-1) {
    int m = (l+r)>>1;

    if(m-l+1 <= L) {
        //bash
        seg[i] = {0, 0};
        for(int j = l; j <= r; j++) {
            seg[i].f = isqrt(seg[i].f + a[j]);
        }
        seg[i].s = seg[i].f+1;
        for(int j = r; j >= l; j--) {
            if(seg[i].s > oo/seg[i].s) seg[i].s = oo;
            else seg[i].s *= seg[i].s;
            seg[i].s -= a[j];
        }
        return;
    }
    
    if(k <= m) upd(k, x, i<<1, l, m);
    else upd(k, x, i<<1|1, m+1, r);
    
    seg[i] = seg[i<<1|1];
    seg[i].s -= seg[i<<1].f;
    if(seg[i].s <= 0) {
        seg[i].f++;
        seg[i].s = oo;
    } else if(seg[i].s == 1) seg[i].s = seg[i<<1].s;
    else seg[i].s = oo;
}

void solve() {
    int q; cin >> n >> q;
    a.resize(n);
    seg.resize(4*n);

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = x;
        upd(i, x);
    }

    for(int i = 0; i < q; i++) {
        int k; ll x; cin >> k >> x;
        a[--k] = x;
        upd(k, x);
        cout << seg[1].f << "\n";
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