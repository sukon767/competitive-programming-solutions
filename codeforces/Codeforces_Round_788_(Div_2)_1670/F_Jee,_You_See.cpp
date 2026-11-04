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
    int n; ll l, r, z; cin >> n >> l >> r >> z; l--;
    vector<mi> dp(2*n+2), fac(n+1), ifac(n+1); //dp[0] is on the dot, dp[1] is 1 off etc.
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i = 2; i <= n; i++) {
        ifac[i] = (-MOD/i)*ifac[MOD%i];
        fac[i] = fac[i-1]*i;
    }
    for(int i = 1; i <= n; i++) ifac[i] *= ifac[i-1];

    mi ans = 0;
    for(int b = 0; b < 2; b++) {
        fill(dp.begin(), dp.end(), 0); dp[0] = 1;

        for(int i = 60; i >= 0; i--) {
            //expand dp
            vector<mi> t(2*n+2);
            for(int j = 0; j <= 2*n+1; j++) {
                if((j<<1|(r>>i&1)) > 2*n) t[2*n+1] += dp[j];
                else t[j<<1|(r>>i&1)] += dp[j];
            }

            dp = t;
            fill(t.begin(), t.end(), 0);

            //knapsack ish
            for(int j = z>>i&1; j <= n; j+=2) {
                mi nCj = fac[n]*ifac[j]*ifac[n-j];
                for(int k = 2*n; k >= j; k--) {
                    t[k-j] += dp[k]*nCj;
                }
                t.back() += dp.back()*nCj;
            }
            dp = t;
        }
        ans += accumulate(dp.begin(), dp.end(), (mi)0)*(b%2 ? -1 : 1);
        swap(r, l);
    }

    cout << ans;
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