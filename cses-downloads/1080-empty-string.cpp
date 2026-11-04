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
void solve() {
    string s; cin >> s;
    int n = sz(s);
    if(n%2==1) {cout << 0; return;}
    vector<mi> fac(n+1), ifac(n+1); fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i = 2; i <= n; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = (-MOD/i)*ifac[MOD%i];
    }
    for(int i = 1; i <= n; i++) ifac[i] *= ifac[i-1];
    vector<vector<mi>> dp(n, vector<mi>(n));
    auto fl = dp;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j < n; j+=2) {
            for(int k = i+2; k < j; k+=2) dp[i][j] += dp[i][k-1]*fl[k][j]*(fac[(j-i+1)/2]*ifac[(k-i)/2]*ifac[(j-k+1)/2]);
            if(s[i] == s[j]) {
                fl[i][j] = i+1==j?1:dp[i+1][j-1];
                dp[i][j] += fl[i][j];
            }
        }
    }
    cout << dp[0][n-1];
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
