#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
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
    int n, M;
    cin >> n >> M;
    MOD = M;

    vector<pair<mi, mi>> dp1 = {{0, 1}, {1, 0}}; //dp[i] means last is position i. .first means last-1 is before.
    vector<mi> b(n+1); b[0] = 1, b[1] = 1, b[2] = 2;
    for(int i = 3; i <= n; i++) {
        vector<pair<mi, mi>> temp(i);
        for(int j = 0; j < i; j++) {
            //.first is last-1 is before last which is always valid. Thus temp[i].first is sum k = 0 to i-1 of dp[k].first + dp[k].second.
            if(j) for(int k = 0; k < j; k++) temp[j].first += dp1[k].first + dp1[k].second;
            if(j < n) for(int k = j; k < i-1; k++) temp[j].second += dp1[k].second;
        }
        dp1 = temp;
        
        for(auto p : dp1) b[i] += p.first + p.second;
    }


    vector<vector<mi>> dp2(n+1, vector<mi>(n+1));
    dp2[0][0] = 1, dp2[1][1] = 1, dp2[2][2] = 2;
    vector<mi> fac(n+1); fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = fac[i-1]*i;
    vector<mi> ifac(n+1); for(int i = 0; i <= n; i++) ifac[i] = 1/fac[i];


    for(int i = 3; i <= n; i++) {
        dp2[i][i] = b[i];
        for(int j = 1; j < i-1; j++) {
            for(int k = 0; k <= j; k++) {
                dp2[i][k + i-j-1] += fac[i-j-1 + k]*ifac[k]*ifac[i-j-1]*dp2[j][k]*b[i-j-1];
            }
        }
    }
    mi ans = 0;
    for(mi x : dp2[n]) ans += x;
    
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