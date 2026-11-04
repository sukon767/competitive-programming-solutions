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
    int n, m; cin >> n >> m;
    int k; cin >> k;

    vector<int> c(k); for(int& i : c) {cin >> i; i--;}

    vector<vector<bool>> dp(n+1);
    dp[1] = {0, 1};

    for(int i = 2; i <= n; i++) {
        dp[i] = vector<bool>(1 << i);
        for(int j = 0; j < (1<<i); j++) {

            if((n-i)%2) dp[i][j] = 1;
            else dp[i][j] = 0;

            for(int l : c) {
                if(l >= i) break;
                int st = (j & ((1<<l)-1)) | ((j>>(l+1))<<l);
                if((n-i)%2) {
                    //bobs turn so take 0
                    if(dp[i-1][st] == 0) {dp[i][j] = 0; break;}
                } else {
                    if(dp[i-1][st] == 1) {dp[i][j] = 1; break;}
                }
            }

        }
    }

    vector<int> cnt(n+1);
    for(int j = 0; j < (1 << n); j++) {
        if(dp[n][j]) {
            cnt[__popcount((unsigned)j)]++;
        }
    }

    vector<mi> arr(m+1);
    for(int x = 1; x <= m; x++) {
        for(int s = 0; s <= n; s++) {
            arr[x] += pow(mi(m-(x-1)), s)*pow(mi(x-1), n-s)*cnt[s];
        }
    }

    mi ans = 0;
    for(int x = 1; x <= m; x++) {
        if(x < m) arr[x] -= arr[x+1];
        ans += arr[x]*x;
    }

    cout << ans;
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