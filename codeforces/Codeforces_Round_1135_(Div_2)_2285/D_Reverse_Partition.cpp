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

//sukon always reads the entire problem statement.
void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<ll> a(n); for(ll& i : a) cin >> i;

    vector<array<int, 3>> que;
    for(int i = 0; i < q; i++) {
        int iv, v; cin >> iv >> v;
        --iv;
        if(iv > n-1-iv) {
            iv = n-1-iv; v = -v;
        }
        que.push_back({iv, v, i});
    }

    sort(que.begin(), que.end());

    map<ll, ll> cnt;
    vector<ll> pre(n), pre2(n);
    partial_sum(all(a), pre.begin());
    reverse(all(a));
    partial_sum(all(a), pre2.begin());
    reverse(all(a));
    for(int i = 0; i <= n-2; i++) {
        cnt[pre[i] - pre2[i]]++;
    }
    ll same = 1 + cnt[0];

    vector<mi> fac(n+1), ifac(n+1); fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i = 2; i <= n; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = (-MOD/i)*ifac[MOD%i];
    }
    for(int i = 1; i <= n; i++) ifac[i] *= ifac[i-1];

    vector<mi> ans(q);
    int on = 0;
    for(auto & [iv, v, ind] : que) {
        while(on < iv) {
            int x1 = on, x2 = n-2-on;
            cnt[pre[x1] - pre2[x1]]--;
            if(x1 != x2) cnt[pre[x2] - pre2[x2]]--;
            on++;
        }

        // cout << (iv+1) << " " << cnt[0] << " " << v << " " << cnt[v] << endl;
        ll qsame = same - cnt[0] + cnt[-v];
        if(m <= qsame) ans[ind] = fac[qsame-1]*ifac[m-1]*ifac[qsame-m];
    }

    for(auto &i : ans) cout << i << "\n";
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