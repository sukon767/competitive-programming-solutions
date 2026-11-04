#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

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
    int nn = 10;
    int n; cin >> n;
    vector<int> a(n);
    vector<mi> p(n);
    for(int &j : a) cin >> j;
    for(mi &j : p) {cin >> j.v; j/=10000;}

    mi ans = 0;

    for(int bit = 0; bit < nn; bit++)
        for(int bit2 = bit; bit2 < nn; bit2++) {
            mi prod1 = 1;
            mi prod2 = 1;
            mi prod3 = 1;
            mi prod4 = 1;

            for(int i = 0; i < n; i++) {
                int x1 = ((1 << bit)&(a[i])) == (1 << bit);
                int x2 = ((1 << bit2)&(a[i])) == (1 << bit2);
                
                prod2 *= 1 + mi(p[i]*(-2*(x2%2)));
                prod3 *= 1 + mi(p[i]*(-2*(x1%2)));
                prod4 *= 1 + mi(p[i]*(-2*((x1+x2)%2)));
            }
            
            mi prod = (prod1-prod2-prod3+prod4)/4*pow((mi)2, bit+bit2);

            ans += prod;
            if(bit != bit2) ans += prod;
        }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}