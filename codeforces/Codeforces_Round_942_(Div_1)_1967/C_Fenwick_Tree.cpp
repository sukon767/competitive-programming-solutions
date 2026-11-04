#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

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
    ll n, k; cin >> n >> k;
    vector<mi> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i].v;

    vector<vector<mi>> dp(n+1);
    for(int i = 1; i <= n; i++) {
        dp[i] = {b[i]};
    }

    const int L = 35;
    vector<mi> fac(L); fac[0] = 1;
    for(int i = 1; i < L; i++) {
        fac[i] = fac[i-1]*(k+i-1)*inv((mi)i);
    }

    for(int i = 2; i <= n; i<<=1) {
        for(int j = i; j <= n; j+=i) {
            dp[j].push_back(0);
            for(int k = sz(dp[j])-1; k > 0; k--) {
                dp[j][k] += dp[j - (i>>1)][k-1];
            }
        }

        for(int j = i; j <= n; j+=(i<<1)) {
            for(int k = 1; k < sz(dp[j]); k++) {
                dp[j][0] -= dp[j][k]*fac[k];
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dp[i][0] << " ";
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