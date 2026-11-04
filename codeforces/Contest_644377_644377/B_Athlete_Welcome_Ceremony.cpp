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

//sukon always reads the entire problem statement.
void solve() {
    int n, Q; cin >> n >> Q;
    string s; cin >> s;
    //number a, number b, last ending.
    vector<vector<array<mi, 3>>> dp(n+1, vector<array<mi, 3>>(n+1));
    if(s[0] == '?') {
        dp[1][0][0] = dp[0][1][1] = dp[0][0][2] = 1;
    } else {
        dp[0][0][s[0]-'a'] = 1;
    }
    int cnt = 0;
    for(char c : s) cnt += (c=='?');
    for(int i = 1; i < n; i++) {
        for(int j = n; j >= 0; j--) {
            for(int k = n; k >= 0; k--) {
                array<mi, 3> t = {0, 0, 0};
                if(s[i] == '?') {
                    if(j) t[0] = dp[j-1][k][1] + dp[j-1][k][2];
                    if(k) t[1] = dp[j][k-1][0] + dp[j][k-1][2];
                    t[2] = dp[j][k][0] + dp[j][k][1];
                } else {
                    int z = s[i]-'a';
                    t[z] = dp[j][k][(z+1)%3] + dp[j][k][(z+2)%3];
                }
                dp[j][k] = t;
            }
        }

        
    }
    
    vector<vector<mi>> pre(n+1, vector<mi>(n+1));
    for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) pre[j][k] = accumulate(all(dp[j][k]), mi(0));
    // for(int j = 0; j <= n; j++)
    //     for(int k = 0; k <= n; k++) {
    //         cout << j << " " << k << " " << pre[j][k] << endl;
    //     }

    for(int j = 1; j <= n; j++) {
        for(int k = n-1; k >= 0; k--) {
            pre[j][k] += pre[j-1][k+1];
        }
    }

    auto left = pre;
    auto up = pre;
    for(auto &v : left) partial_sum(all(v), v.begin());
    for(int j = 1; j <= n; j++) {
        for(int k = 0; k <= n; k++) up[j][k] += up[j-1][k];
    }

    for(int i = 0; i < Q; i++) {
        int x, y, z; cin >> x >> y >> z;
        x = min(x, n), y = min(y, n);

        mi ans = 0;
        int y1 = cnt-x-z;
        if(y1 <= y) ans += left[x][y] - (y1 > 0 ? left[x][y1-1] : 0);
        // cout << x << " " << y << " " << y1 << " " << ans << endl;

        y1 += x;
        if(x && y1 <= x-1) ans += up[x-1][0] - (y1 > 0 ? up[y1-1][0] : 0);
        // cout << x << " " << y << " " << y1 << " " << ans << endl;

        y1 = cnt-y-z-1; //-1 cuz u move diagonally up
        if(x && y < n && y1 <= x-1) ans -= up[x-1][y+1] - (y1 > 0 ? up[y1-1][y+1] : 0);
        // cout << x << " " << y << " " << y1 << " " << ans << endl;

        cout << ans << "\n";
    }    
}

//king of the sun o_O
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