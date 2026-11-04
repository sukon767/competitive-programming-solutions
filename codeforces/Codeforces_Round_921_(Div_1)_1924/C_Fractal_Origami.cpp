#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ll MOD = 999999893;
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
    // 2 + 2sqrt2 + 4 + 4sqrt2...
    // (1-(sqrt2)^n)/((1-(sqrt2)^n) + sqrt2(1-sqrt2))
    // (sqrt2 + 1 - (sqrt2)^{n+1} - (sqrt2)^{n})

    //1 - (sqrt2)^2

    //(2 - 4)/(1-sqrt2)/((2-4)/(1-sqrt2) + 2sqrt2)
    int n; cin >> n;
    if(n==1) {cout << 0; return;}
    n--;
    pair<mi, mi> M, V;
    M.f = 1;
    if(n%2) M.s -= pow(mi(2), n/2);
    else M.f -= pow(mi(2), n/2);
    V = M;
    V.f-=2;
    V.s+=1;

    mi den = V.f*V.f - 2*V.s*V.s;
    pair<mi, mi> ans = {M.f*V.f - M.s*V.s*2, M.s*V.f - M.f*V.s};
    cout << ans.s/den;
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