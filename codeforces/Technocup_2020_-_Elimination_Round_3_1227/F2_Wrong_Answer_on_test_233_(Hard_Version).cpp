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
    int n, k; cin >> n >> k;
    vector<int> h(n); for(int& i : h) cin >> i;
    if(k == 1) {
        cout << 0; return;
    }
    int same = 0, diff = 0;
    for(int i = 0; i < n; i++) {
        if(h[i] == h[(i+1)%n]) same++;
        else diff++;
    }

    vector<mi> fac(n+1), ifac(n+1), p2(n+1), pk2(n+1);
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i = 2; i <= n; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = (-MOD/i)*ifac[MOD%i];
    }
    for(int i = 1; i <= n; i++) ifac[i] *= ifac[i-1];
    p2[0] = pk2[0] = 1;
    for(int i = 1; i <= n; i++) {
        p2[i] = p2[i-1]*2;
        pk2[i] = pk2[i-1]*(k-2);
    }
    mi i2 = (mi)1/2;

    mi ans = 0;
    for(int r = 0; r <= diff; r++) {
        mi t = pk2[r]*fac[diff]*ifac[r]*ifac[diff-r];
        int z = diff-r;
        t *= (p2[z]-(z%2==0 ? fac[z]*ifac[z/2]*ifac[z/2] : 0))*i2;
        ans += t;
        // cout << r << " " << t << endl;
    }
    cout << ans*pow((mi)k, same);
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