#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
//n = m + s.
//say s is p large.
//C_{m, n = m+s} = (C{m, n-1}*C_0 + C{m-1, n-2}*C_1 + ...C{1, s}*C_{m-1}) + C_m.
//(...) = (C{m, n-2}*(1) + C{m-1, n-3}*(C_0 + C_1) + .. C{1, s-1}*C{m-2}) + (C_0 + ... + C{m-1})
//(...) = (C{m, n-k}*(1) + C{m-1, n-k-1}*(C_0*((k-1 + 1) choose k-1) + C_1*(k-1 choose k-1)  ) + ... ((m choose k-1)*C_0 + (k-1 choose k-1)*C{m-k+1})
//before hrs... sum C_i(sum_{k=0, s-1} (m-i choose k)).
//(1+x)^
//(...)  now we are on k = s. = (C_m*(C_0) + C_{m-1, m-1}*(C_0*(s choose s-1) + C_1)     )
//(...) = C{m, n-2}*(1) + C{m-1, n-3}*(1 + C{1, 1}) + C{m-n+3, 1}*(1 + ... C{n-3, n-3}) + (1 + ... C{n-2, n-2}).
//(...) = ... + ((n-2)*C{0, 0} + ... 1*C{n-3, n-3}) >> c_0, 2C_0 + c_1, 3c_0 + 2c_1 + c_2, 4c_0 + 3c_1 + ..
//(...) = ... + (( (n-2) choose 2)*C{0, 0} + (2 choose 2)*C{n-4, n-4})
//(...) = 
//(C{m, n-2})*(1) + C{m-1, n-3}*(1 + C{1, 1}) + ...
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
    int n, k; cin >> n;
    if(n%2) {cout << 0; return;}
    string s; cin >> s;
    k = sz(s);
    int y = n/2, x = n/2;
    int pre = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == '(') {
            x--;
            pre++;
        } else {
            y--;
            pre--;
        }
        if(pre < 0) {cout << 0; return;}
    }
    if(x < 0 || y < 0) {cout << 0; return;}
    vector<mi> fac(n+1), in(n+1), ifac(n+1);
    fac[0] = in[0] = in[1] = ifac[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i > 1) in[i] = (-MOD/i)*in[MOD%i];
        ifac[i] = ifac[i-1]*in[i];
        fac[i] = fac[i-1]*i;
    }
    // cout << n << " " << k << ' ' << s << endl;
    int z = y-x;
    mi ans = (fac[2*x+z]*ifac[x]*ifac[x+z]);
    if(x) ans -= (fac[2*x+z]*ifac[x-1]*ifac[x+z+1]);
    cout << ans;
    // cout << mi(y+1-x)/mi(y+1+x)*(fac[y+x+1]*ifac[x]*ifac[y+1]);
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
