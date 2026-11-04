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

vector<vector<int>> dp;
vector<mi> p2;

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(all(a));
    mi ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ans += p2[max(0, j-i-1)]*dp[a[i]][a[j]];
        }
    }

    cout << ans;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int n = 3000;
    dp = vector<vector<int>>(n+1, vector<int>(n+1));
    vector<int> rad(n+1, 1);
    for(int i = 2; i <= n; i++) {
        if(rad[i] == 1) {
            for(int j = i; j <= n; j+=i) rad[j] *= i;
        }
    }
    
    vector<vector<int>> bad(n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = rad[i]; j <= n; j+=rad[i]) bad[j].push_back(i);
    }

    for(int j = 1; j <= n; j++) dp[j][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            //largest <= j in bad[i].
            auto it = upper_bound(all(bad[i]), j);
            int jx = *prev(it);
            if(i == jx) dp[i][j] = dp[i][i];
            else dp[i][j] = dp[i-1][jx-1];
        }
    }

    p2 = vector<mi>(n+1); p2[0] = 1;
    for(int i = 1; i <= n; i++) p2[i] = p2[i-1]*2;
    
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