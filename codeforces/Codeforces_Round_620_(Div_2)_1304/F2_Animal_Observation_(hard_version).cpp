#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

struct lztree {
    typedef ll T; T idT = {}; //identity for combining segtree nodes
    typedef ll U; U idU = {}; //identity for updates
    // combining segtree nodes a and b
    T f(T a, T b) { return max(a, b); }
    // applying updates a and b (in that order)
    U g(U b, U a) { return a + b; }
    // applying update b to segtree node a
    T h(U b, T a) { return a + b; }
    int n;
    vector<T> t;
    vector<U> d;
    lztree(int n, vector<ll>& vv) : n(n), t(2*n, idT), d(n, idU) {
        for(int i = n; i < 2*n; i++) t[i] = vv[i-n];
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
    int n, m, k; cin >> n >> m >> k;
    vector<ll> ini(m);
    vector<ll> ai1(m);
    for(int i = 0; i < min(n, 2); i++) {
        for(int j = 0; j < m; j++) {
            ll v; cin >> v; ini[j]+=v;
            ai1[j] = v;
        }
    }
    partial_sum(all(ini), ini.begin());
    vector<ll> dp(m-k+1); for(int i = 0; i <= m-k; i++) dp[i] = ini[i+k-1] - (i?ini[i-1]:0);
    if(n == 1) {
        cout << *max_element(all(dp)); return;
    }

    for(int i = 2; i <= n; i++) {
        vector<ll> nxt(m-k+1);
        vector<ll> ai(m), pre(m);
        if(i < n) for(auto &i : ai) cin >> i;
        else fill(all(ai), 0);
        for(int i = 0; i < m; i++) {
            if(i) pre[i] += pre[i-1];
            pre[i] += ai[i] + ai1[i];
        }
        
        lztree prev(sz(dp), dp);
        for(int j = 0; j < k; j++) {
            prev.modify(0, min(j, m-k), -ai1[j]);
        }

        for(int j = 0; j <= m-k; j++) {
            nxt[j] = (pre[j+k-1] - (j?pre[j-1]:0)) + prev.query(0, m-k);
            //transition
            if(j < m-k) {
                prev.modify(max(0, j-k+1), j, ai1[j]);
                prev.modify(j+1, min(m-k, j+k), -ai1[j+k]);
            }
        }

        dp = nxt;
        ai1 = ai;

        // for(ll x : dp) cout << x << " ";
        // cout << endl;
    }

    cout << *max_element(all(dp));
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