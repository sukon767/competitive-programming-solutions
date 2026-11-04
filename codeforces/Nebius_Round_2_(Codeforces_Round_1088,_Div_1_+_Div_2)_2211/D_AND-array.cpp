#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

ll MOD = 1e9+7;
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
    ll n; cin >> n;
    vector<mi> b(n);
    vector<ll> f(29);
    for(mi &i : b) cin >> i.v;
    vector<mi> fac(n+1), ifac(n+1); fac[0] = 1;

    for(ll i = 1; i <= n; i++) fac[i] = fac[i-1]*i;
    for(ll i = 0; i <= n; i++) ifac[i] = inv(fac[i]);

    for(ll i = n-1; i >= 0; i--) {
        if(b[i].v) {
            for(ll j = 0; j < 29; j++) {
                if((b[i].v >> j) & 1) {
                    f[j] = i+1;
                }
            }

            for(ll j = 0; j <= i; j++) {
                b[j] -= b[i]*fac[i+1]*ifac[j+1]*ifac[i-j];
            }
        }
    }

    vector<ll> a(n);

    for(ll b = 0; b < 29; b++) {
        for(ll j = 0; j < f[b]; j++) {
            a[j] |= (1LL << b);
        }
    }

    for(ll x : a) cout << x << " ";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}