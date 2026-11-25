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

vector<vector<mi>> c;

//sukon always reads the entire problem statement.
void solve() {
    ll n, m, k; cin >> n >> m >> k;
    mi ans = 0;
    //dp[i][j] is prod 1/(1-x)^r for r <= i, and then the x^j coeff. this signifies k = i+j.
    mi im = (mi)1/m, mm = pow((mi)m, n), oo = 1, fall = 1;
    for(int i = 0; i <= min(n, k); i++) {
        ans += c[i][k-i]*oo*mm*fall;
        oo *= m/2 + m%2; mm *= im; fall *= n-i;
    }
    cout << ans;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int K = 2000;
    c = vector<vector<mi>>(K+1, vector<mi>(K+1));
    c[0][0] = 1;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j <= K; j++) {
            c[i][j] = c[i-1][j] + (j ? c[i][j-1]*i : 0);
        }
    }

    int t; cin >> t;
    // int t = 1;
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