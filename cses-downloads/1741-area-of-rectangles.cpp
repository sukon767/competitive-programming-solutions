#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
struct lztree {
    typedef pair<ll, ll> T; T idT = {LLONG_MAX, 0}; //identity for combining segtree nodes
    typedef ll U; U idU = {}; //identity for updates
    // combining segtree nodes a and b
    T f(T a, T b) {
        if(a.f > b.f) swap(a, b);
        if(a.f == b.f) return {a.f, a.s+b.s};
        return a;
    }
    // applying updates a and b (in that order)
    U g(U b, U a) { return a + b; }
    // applying update b to segtree node a
    T h(U b, T a) { return {a.f + b, a.s}; }
    int n;
    vector<T> t;
    vector<U> d;
    lztree(int n) : n(n), t(2*n, idT), d(n, idU) {
        //when we don't want to initialize to idT.
        for(int i = n; i < 2*n; i++)
            t[i] = {0, 1}; //initial value of a leaf i-n.
        for(int i = n-1; i > 0; i--)
            calc(i);
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
    int n; cin >> n;
    const int N = 2e6+1;
    lztree seg(N);
    vector<vector<array<int, 3>>> upd(N);
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1+=N/2; x2+=N/2; y1+=N/2; y2+=N/2;
        upd[x1].push_back({y1, y2-1, 1});
        upd[x2].push_back({y1, y2-1, -1});
    }
    ll ans = 0;
    ll cur = N;
    for(int i = 0; i < N; i++) {
        for(auto &v : upd[i]) {
            seg.modify(v[0], v[1], v[2]);
        }
        if(sz(upd[i])) {
            auto qu = seg.query(0, N-1);
            cur = (qu.f ? 0 : qu.s);
        }
        // if(N-cur) cout << i-N/2 << " " << N-cur << endl;
        ans += N-cur;
    }
    cout << ans;
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
