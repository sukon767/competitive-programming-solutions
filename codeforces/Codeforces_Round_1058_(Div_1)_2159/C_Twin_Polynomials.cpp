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
    int n; cin >> n;
    vector<int> a(n+1); for(int& i : a) cin >> i;

    vector<int> child(n+1, -1);

    int l = n;
    for(int i = 1; i <= n; i++) {
        if(a[i] > n) {
            cout << 0; return;
        }
        if(a[i] != -1) {
            if(child[i] != -1 && child[i] != a[i]) {
                cout << 0; return;
            }
            if(child[i] == -1) {
                if(i == a[i]) {
                    child[i] = i;
                    l--;
                } else {
                    if(child[a[i]] != -1) {cout << 0; return;}
                    child[i] = a[i]; l--;
                    if(a[i]) {
                        child[a[i]] = i;
                        l--;
                    }
                }
            }
        }
    }

    // cout << l << endl;
    vector<mi> dp(l+1);
    dp[0] = 1;
    for(int i = 1; i <= l; i++) {
        dp[i] = dp[i-1] + (i>1 ? (i-1)*dp[i-2] : 0);
        if(i < l) dp[i] += dp[i-1];
    }

    if(child[n] == -1 || l==0) cout << dp[l];
    else cout << dp[l]+dp[l-1];
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