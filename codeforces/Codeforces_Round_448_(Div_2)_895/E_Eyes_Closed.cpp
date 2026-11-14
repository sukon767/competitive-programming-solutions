#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<int> a;

struct lztree {
    typedef pair<double, int> T; T idT = {0, 0}; //identity for combining segtree nodes
    typedef pair<double, double> U; U idU = {1, 0}; //identity for updates
    // combining segtree nodes a and b
    T f(T a, T b) { return {a.f + b.f, a.s + b.s}; }
    // applying updates a and b (in that order)
    U g(U b, U a) { return {b.f*a.f, a.s*b.f + b.s}; }
    // applying update b to segtree node a
    T h(U b, T a) { return {a.f*b.f + a.s*b.s, a.s}; }
    int n;
    vector<T> t;
    vector<U> d;
    lztree(int n) : n(n), t(2*n, idT), d(n, idU) {
        for(int i = n; i < 2*n; i++) t[i] = {a[i-n], 1};
        for(int i = n-1; i > 0; i--) calc(i);
    }
    void calc(ll p) { t[p] = h(d[p], f(t[p*2], t[p*2+1])); }
    void apply(ll p, U v) {
        t[p] = h(v, t[p]);
        if(p < n) d[p] = g(v, d[p]);
    }
    void push(ll p) {
        p += n;
        for(int s = 19; s > 0; s--){
            ll i = p >> s;
            if(d[i] != idU) {
                apply(i * 2, d[i]);
                apply(i * 2 + 1, d[i]);
                d[i] = idU;
            }
        }
    }
    void modify(ll p, T v) {
        push(p);
        t[p += n] = v;
        while(p > 1) calc(p /= 2);
    }
    void modify(ll l, ll r, U v) {
        r++;
        push(l), push(r - 1);
        bool cl = false, cr = false;
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(cl) calc(l - 1);
            if(cr) calc(r);
            if(l & 1) apply(l++, v), cl = true;
            if(r & 1) apply(--r, v), cr = true;
        }
        for(--l; r; l /= 2, r /= 2) {
            if(cl) calc(l);
            if(cr) calc(r);
        }
    }
    T query(ll l, ll r) {
        r++;
        push(l), push(r - 1);
        T resl = idT, resr = idT;
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
};

//sukon always reads the entire problem statement.
void solve() {
    int n, q; cin >> n >> q;
    a = vector<int>(n); for(auto &i : a) cin >> i;
    lztree lz(n);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
            double s1 = lz.query(--l1, --r1).f, s2 = lz.query(--l2, --r2).f;
            int d1 = r1-l1+1, d2 = r2-l2+1;
            lz.modify(l1, r1, {1 - 1.0/d1, 1.0/d1*s2/d2});
            lz.modify(l2, r2, {1 - 1.0/d2, 1.0/d2*s1/d1});
        } else {
            int l, r; cin >> l >> r;
            cout << setprecision(20) << lz.query(--l, --r).f << "\n";
        }
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