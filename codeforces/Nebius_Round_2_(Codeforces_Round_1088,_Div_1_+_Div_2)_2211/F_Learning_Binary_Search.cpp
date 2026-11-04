#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
ll MOD = 676767677;
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

vector<int> dep;
vector<mi> iv, fac, ifac;
mi ans;
int n, m;

void dfs(int l, int r, int d) {
    int i = (l+r)>>1;
    pair<int, int> p = {l-1, r+1};
    dep[i] = d;

    mi t = 0;
    t += fac[m-1+n]*ifac[n]*ifac[m-1];
    if(-1 < p.first) t -= fac[m-1+n - (i - p.first)]*ifac[m-1]*ifac[n - (i-p.first)];
    if(p.second < n) t -= fac[m-1+n - (p.second - i)]*ifac[m-1]*ifac[n - (p.second - i)];
    if(-1 < p.first && p.second < n) t += fac[m-1+n - (p.second - p.first)]*ifac[m-1]*ifac[n - (p.second - p.first)];
    ans += t*dep[i];

    if(l <= i-1) dfs(l, i-1, d+1);
    if(i+1 <= r) dfs(i+1, r, d+1);
}

void solve() {
    cin >> n >> m;
    dep = vector<int>(n);
    ans = 0;
    dfs(0, n-1, 1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MN = 2e6;
    iv = fac = ifac = vector<mi>(MN+1);
    iv[0] = iv[1] = fac[0] = ifac[0] = 1;
    for(int i = 1; i <= MN; i++) {
        if(i >= 2) iv[i] = (MOD-MOD/i)*iv[MOD%i];
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1]*iv[i];
    }

    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}