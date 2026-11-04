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

vector<int> rad;

void solve() {
    int n; cin >> n;
    vector<int> f(n+1), p(n+1), dp(n+1);
    //2^{n-(# <= x) - (# >= y)} * (#x) * (#y) *dp[x][y]
    //2^n * (f[x] * 2^{-p[x]}) * sum (f[y] * 2^{-(n-p[y-1])}) * dp[x][y].
    vector<mi> w(n+1), p2(n+1), ip2(n+1);
    p2[0] = ip2[0] = 1; p2[1] = 2; ip2[1] = (MOD+1)/2;
    for(int i = 2; i <= n; i++) {
        p2[i] = p2[i-1]*2;
        ip2[i] = ip2[i-1]*ip2[1];
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x; f[x]++;
    }
    partial_sum(all(f), p.begin());
    for(int i = 1; i <= n; i++) w[i] = (p2[f[i]]-1)*ip2[p[i]];

    mi ans = 0;
    mi sum = 0;
    for(int i = 1; i <= n; i++) {
        //transition
        if(i > 1) {
            for(int j = i-rad[i]; j > 0; j -= rad[i]) {
                sum -= w[j]*dp[j];
                dp[j] = dp[j-1];
                sum += w[j]*dp[j];
            }
        }
        // for(int j = 1; j <= i; j++) cout << j << " " << i << " " << w[j] << " " << dp[j] << endl;
        ans += ip2[n-p[i-1]]*(p2[f[i]]-1)*sum;
        dp[i] = i; sum += w[i]*dp[i];
    }
    ans *= p2[n];
    for(int i = 1; i <= n; i++) ans += (p2[f[i]]-1)*i;
    cout << ans;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int n = 3e5;
    rad = vector<int>(n+1, 1);
    for(int i = 2; i <= n; i++) {
        if(rad[i] == 1) {
            for(int j = i; j <= n; j+=i) rad[j] *= i;
        }
    }

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