#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ll MOD = 1e9+7;
struct mi {
ll v;
explicit operator ll() const { return v; }
mi() { v = 0; }
mi(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }
bool operator<(const mi& other) const {
return v < other.v;
}
friend std::ostream& operator<<(std::ostream& os, const mi& m) {
  os << m.v;
  return os;
}
};
mi &operator+=(mi &a, mi b) {
if ((a.v += b.v) >= MOD) a.v -= MOD;
return a;
}
mi &operator-=(mi &a, mi b) {
if ((a.v -= b.v) < 0) a.v += MOD;
return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(a.v * ll(b.v)); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, ll p) {
assert(p >= 0);
return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
assert(a.v != 0);
return pow(a, MOD-2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
mi& operator/=(mi& a, mi b) { return a = a/b; }
bool operator==(mi a, mi b) {return a.v == b.v;}
bool operator!=(mi a, mi b) {return a.v != b.v;}

struct lztree {
    typedef pair<mi, ll> T; T idT = {1, 0}; //identity for combining segtree nodes
    typedef mi U; U idU = 1; //identity for updates
    // combining segtree nodes a and b
    T f(T a, T b) { return {a.f * b.f, a.s + b.s}; }
    // applying updates a and b (in that order)
    U g(U b, U a) { return a * b; }
    // applying update b to segtree node a
    T h(U b, T a) { return {a.f*pow(b, a.s), a.s}; }
    int n;
    vector<T> t;
    vector<U> d;
    lztree(int n) : n(n), t(2*n, idT), d(n, idU) {
        for(int i = n; i < 2*n; i++) t[i] = {1, 1};
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

struct lztree2 {
    typedef ll T; T idT = 0; //identity for combining segtree nodes
    typedef ll U; U idU = 0; //identity for updates
    // combining segtree nodes a and b
    T f(T a, T b) { return a | b; }
    // applying updates a and b (in that order)
    U g(U b, U a) { return a | b; }
    // applying update b to segtree node a
    T h(U b, T a) { return a | b; }
    int n;
    vector<T> t;
    vector<U> d;
    lztree2(int n) : n(n), t(2*n, idT), d(n, idU) {}
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

const int F = 4e5;

//sukon always reads the entire problem statement.
void solve() {
    int n, q; cin >> n >> q;
    const int N = 300;
    vector<int> fac(N+1);
    lztree2 bt(n);
    map<int, int> bts;
    vector<int> ps;
    for(int i = 2; i <= N; i++) {
        if(fac[i]) continue;
        bts[i] = sz(ps);
        ps.push_back(i);
        for(int j = i; j <= N; j+=i) fac[j] = i;
    }

    lztree prod(n);
    vector<mi> iv(N+1); iv[0] = iv[1] = 1;
    for(int i = 2; i <= N; i++) {
        iv[i] = (-MOD/i)*iv[MOD%i];
    }

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        prod.modify(i, {x, 1});
        vector<int> pf;
        while(x>1) {
            if(pf.empty() || pf.back() != fac[x]) pf.push_back(fac[x]);
            x /= fac[x];
        }
        for(auto& p : pf) bt.modify(i, i, (1LL<<bts[p]));
    }

    while(q--) {
        string s; cin >> s;
        int l, r; cin >> l >> r;
        l--, r--;
        if(s == "MULTIPLY") {
            int x; cin >> x;
            prod.modify(l, r, x);
            vector<int> pf;
            while(x>1) {
                if(pf.empty() || pf.back() != fac[x]) pf.push_back(fac[x]);
                x /= fac[x];
            }
            for(auto& p : pf) bt.modify(l, r, (1LL<<bts[p]));
        } else {
            mi ans = prod.query(l, r).f;
            ll msk = bt.query(l, r);
            for(int i = 0; i < sz(ps); i++) {
                if(msk>>i&1) {
                    ll p = ps[i];
                    ans *= (p-1)*iv[p];
                }
            }
            cout << ans << "\n";
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