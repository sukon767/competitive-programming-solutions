#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

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

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<int> pre(m1), suf(m2);
    for(int& i : pre) cin >> i;
    for(int& i : suf) cin >> i;
    vector<mi> fac(n+1), in(n+1), ifac(n+1);
    fac[0] = in[0] = in[1] = ifac[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i > 1) in[i] = (-MOD/i)*in[MOD%i];
        ifac[i] = ifac[i-1]*in[i];
        fac[i] = fac[i-1]*i;
    }

    if(pre[0] != 1 || suf.back() != n) {cout << 0; return;}
    if(pre.back() != suf[0]) {cout << 0; return;}

    reverse(suf.begin(), suf.end());
    for(int i = 0; i < m2; i++) suf[i] = n+1-suf[i];
    vector<vector<int>> p2 = {pre, suf};

    mi ans = 1;

    for(int j = 0; j < 2; j++) {
        for(int i = 1; i < sz(p2[j]); i++) {
            int bef = p2[j][i-1]-1;
            int ad = p2[j][i]-1-p2[j][i-1];
            ans *= fac[bef+ad]*ifac[bef];
        }
    }

    int piv = pre.back();
    ans *= fac[n-1]*ifac[piv-1]*ifac[n-piv];
    
    cout << ans;
}
 
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */