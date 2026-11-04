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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<vector<ll>>> ri(m+1);
    vector<mi> dp(m+1);
    vector<mi> prod(m+1, 1);
    for(int i = 0; i < n; i++) {
        ll l, r, p, q; cin >> l >> r >> p >> q; l--;
        ri[l].push_back({r, p, q});
        prod[l] *= (1-mi(p)/q);
    }
    for(int i = 1; i <= m; i++) prod[i] *= prod[i-1];

    dp[0] = 1;

    for(int i = 0; i < m; i++) {
        // cout << i << " " << dp[i] << " " << mi(1)/9 << endl;
        for(auto& pi : ri[i]) {
            ll r = pi[0], p = pi[1], q = pi[2];
            dp[r] += mi(p)/q*dp[i]*(prod[r-1]/(i ? prod[i-1] : 1))/(1- mi(p)/q);
        }
    }
    
    cout << dp.back();
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