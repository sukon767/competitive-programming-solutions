#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

const ll MOD = 998244353;
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

struct Hell {
    //a - no neg non/ind answer
    //b - neg non/ind answer
    //d - no neg sum/ind
    //nd - neg cnt/ind
    mi a1 = 0, a2 = 0, b1 = 0, b2 = 0, d2 = 0, nd2 = 0, nn1 = 0, nn2 = 0;
    ll d1 = 0, nd1 = 0;
};

int n;
vector<mi> fac, ifac;
vector<Hell> seg;

Hell merge(Hell x, Hell y) {
    Hell z;
    z.a1 = x.a1 + y.a1 + (mi)x.d1*y.d1*2;
    z.a2 = x.a2 + y.a2 + x.d1*y.d2*2;
    z.b1 = x.b1 + y.b1 + ((mi)x.nd1*y.d1 + (mi)x.d1*y.nd1)*2;
    z.b2 = x.b2 + y.b2 + (x.nd1*y.d2 + x.d1*y.nd2)*2;
    z.d1 = x.d1 + y.d1;
    z.d2 = x.d2 + y.d2;
    z.nd1 = x.nd1 + y.nd1;
    z.nd2 = x.nd2 + y.nd2;
    z.nn1 = x.nn1 + y.nn1 + (mi)x.nd1*y.nd1*2;
    z.nn2 = x.nn2 + y.nn2 + x.nd1*y.nd2*2;
    return z;
}

void upd(int ind, int v, int i = 1, int l = 0, int r = n-1) {
    auto& z = seg[i];
    if(l == r) {
        if(v == -1) {
            z.a1 = z.a2 = z.d2 = 0; z.d1 = 0;
            z.nd1 = 1; z.nd2 = l;
        } else {
            z.nd1 = 0; z.nd2 = 0;
            z.a1 = mi(v)*v, z.d1 = v; z.a2 = l*z.a1, z.d2 = l*z.d1;
        }
        return;
    }

    int m = (l+r)>>1;
    if(ind <= m) upd(ind, v, i<<1, l, m);
    else upd(ind, v, i<<1|1, m+1, r);

    z = merge(seg[i<<1], seg[i<<1|1]);
}

Hell query(Hell ans, int p, int q, int i = 1, int l = 0, int r = n-1) {
    
    if(p <= l && r <= q) {
        //merge ans, (l, r).
        return merge(ans, seg[i]);
    }
    int m = (l+r)>>1;
    if(p <= m) ans = query(ans, p, q, i<<1, l, m);
    if(m+1 <= q) ans = query(ans, p, q, i<<1|1, m+1, r);
    return ans;
}

mi binom(ll n, ll k) {
    if(k > n) return 0;
    assert(n >= 0 && k >= 0);
    return fac[n]*ifac[k]*ifac[n-k];
}

void solve() {
    int q; cin >> n >> q;
    vector<int> a(n);
    seg = vector<Hell>(4*n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        upd(i, a[i]);
    }

    Hell t;
    t = query(t, 0, n-1);

    for(int i = 0; i < q; i++) {
        int c; cin >> c;
        if(c == 1) {
            int p, v; cin >> p >> v;
            upd(--p, v);
        } else {
            int l, r, m; cin >> l >> r >> m;
            Hell qu;
            qu = query(qu, --l, --r);

            if(qu.nd1 == 0) {
                if(qu.d1 == m) {
                    cout << (r+1)*qu.a1 - qu.a2;
                } else cout << 0;
            } else {
                ll r1 = m-qu.d1, k = qu.nd1;
                mi f1 = binom(r1+k-1, k-1), f2 = binom(r1+k-1, k), f3 = binom(r1+k-1, k+1);
                mi ans = f1*((r+1)*qu.a1 - qu.a2) + f2*((r+1)*qu.b1 - qu.b2) + f3*((r+1)*qu.nn1 - qu.nn2) + (f2+2*f3)*((r+1)*qu.nd1 - qu.nd2);
                // cout << qu.a1 << " " << qu.a2 << " " << qu.b1 << " " << qu.b2 << endl;
                // cout << qu.nd1 << " " << qu.nd1 << endl;
                // cout << f1*((r+1)*qu.a1 - qu.a2) << " " << f2*((r+1)*qu.b1 - qu.b2) << " " << f3*((r+1)*qu.nn1 - qu.nn2) << " " << (f2+2*f3)*((r+1)*qu.nd1 - qu.nd2) << endl;
                cout << ans;
            }


            cout << "\n";
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1300000;
    fac = ifac = vector<mi>(N+1);
    fac[0] = ifac[0] = ifac[1] = 1;
    for(int i = 1; i <= N; i++) {
        if(i > 1) ifac[i] = (-MOD/i)*ifac[MOD%i];
        fac[i] = fac[i-1]*i;
    }
    for(int i = 1; i <= N; i++) ifac[i] *= ifac[i-1];

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */