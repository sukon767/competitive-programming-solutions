#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

ll MOD = 998244353;
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
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<vector<mi>> dp(n+1, vector<mi>(n+1));
    vector<vector<mi>> dp2(n+1, vector<mi>(n+1));
    dp[0][0] = 1;
    dp2[0][0] = dp2[0][1] = 1;
    
    int l = 0;
    vector<mi> fac(n+1), in(n+1), ifac(n+1); fac[0] = in[0] = in[1] = ifac[0] = 1;
    for(int i = 1; i <= n; i++) {
        fac[i] = fac[i-1]*i;
        if(i > 1) in[i] = (-MOD/i)*in[MOD%i];
        ifac[i] = ifac[i-1]*in[i];
    }

    for(int i = 1; i <= n; i++) {
        while(2*a[l] <= a[i-1]) l++;

        for(int j = 0; j <= l+1; j++) {
            dp[i][j] += dp[i-1][j];

            mi t = 0;
            for(int r = 0; r <= j-1; r++) {
                t += dp2[l][j-1-r];
            }

            // dp[i][j] += t*ifac[l-j+1];

            // cout << endl << l << " " << j << " " << dp2[l][j] << endl; 
            if(j) dp[i][j] += dp2[l][j-1]*ifac[l-j+1];
        }

        if(i < n) {
            for(int j = 0; j <= i; j++) {
                dp2[i][j] = dp[i][j]*fac[i-j];
                if(j) dp2[i][j] += dp2[i][j-1];
            }
        }
        
    }

    cout << dp[n][n];

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