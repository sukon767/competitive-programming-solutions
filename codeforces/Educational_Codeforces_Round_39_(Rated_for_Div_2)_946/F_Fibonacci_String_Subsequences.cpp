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

template <typename T>
vector<vector<T>> matMul(const vector<vector<T>>& a, const vector<vector<T>>& b) {
    assert(sz(a) && sz(b) && sz(a[0]) && sz(b[0]) && sz(a[0]) == sz(b));
    vector<vector<T>> ans(sz(a), vector<T>(sz(b[0])));
    for(int i = 0; i < sz(a); i++) {
        for(int j = 0; j < sz(b[0]); j++) {
            for(int k = 0; k < sz(b); k++) {
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

template <typename T>
vector<vector<T>> matExp(vector<vector<T>> a, ll N) {
    int n = sz(a);
    assert(n && n == sz(a[0]));
    vector<vector<T>> ans(n, vector<T>(n));
    for(int i = 0; i < n; i++) ans[i][i] = 1;
    while(N) {
        if(N&1) ans = matMul(ans, a);
        a = matMul(a, a);
        N>>=1;
    }
    return ans;
}

void solve() {
    int n, x; cin >> n >> x;
    string s; cin >> s;

    vector<int> pi(n); //lps[i].
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    //build matrices
    vector<vector<mi>> m1(n+1, vector<mi>(n+1)), m2(n+1, vector<mi>(n+1));

    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && s[j] != '0')
            j = pi[j-1];
        if(s[j] == '0')
            j++;
        m1[i][j] = 1;
        if(j==n) m1[i][pi[n-1]] = 1;
    }

    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && s[j] != '1')
            j = pi[j-1];
        if(s[j] == '1')
            j++;
        m2[i][j] = 1;
        if(j==n) m2[i][pi[n-1]] = 1;
    }

    m1[n][n] = m2[n][n] = 2;

    for(int i = 0; i < n; i++) {
        m1[i][i] += 1;
        m2[i][i] += 1;
    }

    if(!x) {
        cout << m1[0][n];
        return;
    }

    for(int i = 2; i <= x; i++) {
        auto m3 = matMul(m2, m1);
        m1 = m2, m2 = m3;
    }

    cout << m2[0][n];
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