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
    int n; cin >> n;
    int m[n+1];
    for(int i = 1; i <= n; i++) cin >> m[i];
    if(m[1]==n) {cout << 0; return;}
    mi val[n+1][n+1];
    vector<pair<int, int>> lis;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= m[i]; j++) lis.push_back({i, j});
    }
    auto len = lis; sort(all(len), [](const auto& a, const auto& b) {return a.s-a.f < b.s-b.f;});

    mi dp[n+1][n+1][n+1];
    for(int i = 1; i <= n; i++) dp[i][i-1][0]=1;

    mi fac[n+1]; fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i]=fac[i-1]*i;

    for(int i = 0; i < sz(len); i++) {
        auto& [l, r] = len[i];
        if(l < r) dp[l][r-1][r-l]-=val[l][r-1];
        for(int k = 0; k <= n; k++) dp[l][r][k] += dp[l][r-1][k];
        for(auto& p : lis) {
            if(l < p.f && r == p.s) {
                int l1 = p.f;
                int d = r-l1+1;
                for(int k = 0; k+d <= n; k++) dp[l][r][k+d] -= dp[l][l1-1][k]*val[l1][r];
            }
        }
        for(int i = 0; i <= r-l+1; i++) val[l][r] += fac[(r-l+1)-i]*dp[l][r][i];
    }
    
    mi dp2[n+1][n+1]; dp2[0][0]=1;
    mi ans = 0;
    int ind = 0;
    for(int i = 0; i <= n; i++) {
        if(i) for(int k = 0; k <= n; k++) dp2[i][k] += dp2[i-1][k];
        while(ind < sz(lis) && lis[ind].f==i+1) {
            auto& [_, r1] = lis[ind];
            int d = r1-i;
            for(int k = 0; k+d <= n; k++) dp2[r1][k+d] -= dp2[i][k]*val[i+1][r1];
            ind++;
        }
    }

    for(int i = 0; i <= n; i++) ans += fac[n-i]*dp2[n][i];
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