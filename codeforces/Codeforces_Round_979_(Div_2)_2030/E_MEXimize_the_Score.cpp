#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
ll MOD = 998244353;
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {int u; cin >> u; a[u]++;}
    vector<mi> fac(n+1), b(n+1, 1);
    fac[0] = 1; for(int i = 1; i <= n; i++) fac[i] = fac[i-1]*i;
    mi cp = pow(mi(2), n), d2 = mi(1)/2, ans = 0;
    int msf = n;
    for(int i = 0; i < n; i++) {
        if(!a[i]) break;
        msf = min(msf, a[i]);
        cp *= pow(d2, a[i]);
        mi cur = pow(mi(2), a[i]), curpre = 0, t = 0;
        for(int j = 0; j < a[i]; j++) {
            if(j < msf) curpre += b[j];
            t += curpre*fac[a[i]]/fac[j+1]/fac[a[i]-j-1];
            if(j < msf) {
                cur -= fac[a[i]]/fac[j]/fac[a[i]-j];
                b[j] *= cur;
            }
        }
        ans += t*cp;
    }
    cout << ans;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}