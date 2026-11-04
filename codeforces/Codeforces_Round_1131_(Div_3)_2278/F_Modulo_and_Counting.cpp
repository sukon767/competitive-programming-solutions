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

//sukon always reads the entire problem statement.
void solve() {
    //a1 - am - arb = m.
    //(m+2) - 1 - 1 = m, or no carries with m+1, 1 / m+2, 2.
    //1 -> 2 is always bad. so case 2 is impossible.
    //case 1: an-1 = 2. so its 2, 1 and then each next is within 2 ending at m+2.
    //case 3: an = 2. and no carries. so its just like n-1 + n answer for starting at 2.
    int n, m; cin >> n >> m;
    vector<vector<mi>> dp(n, vector<mi>(m+3)), pre(n, vector<mi>(m+3));
    dp[0][2] = 1;
    partial_sum(dp[0].begin(), dp[0].end(), pre[0].begin());
    for(int i = 1; i < n; i++) {
        for(int j = 2; j <= m+2; j++) {
            dp[i][j] = pre[i-1][j] - pre[i-1][j/2];
        }
        partial_sum(dp[i].begin(), dp[i].end(), pre[i].begin());
    }
    mi ans = 0;
    for(int i = 0; i < n; i++) ans += dp[i][m+2];
    cout << ans;
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