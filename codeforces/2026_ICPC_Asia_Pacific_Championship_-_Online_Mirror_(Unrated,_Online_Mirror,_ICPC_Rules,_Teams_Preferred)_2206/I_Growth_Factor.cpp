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
    vector<int> a(n); for(int &i : a) cin >> i;
    for(int i = n-2; i >= 0; i--) a[i] = min(a[i], a[i+1]);
    int N = 2e5;
    vector<int> g(N+1);
    for(int i = 0; i < n; i++) {
        int lo = i ? a[i-1]+1 : 1;
        for(int j = lo; j <= a[i]; j++) g[j] = i+1;
    }

    vector<mi> fac(N+1), ifac(N+1); fac[0] = 1; for(int i = 1; i <= N; i++) fac[i] = fac[i-1]*i;
    for(int i = 0; i <= N; i++) ifac[i] = 1/fac[i];
    vector<vector<mi>> D(N+1, vector<mi>(20));

    for(int i = 1; i <= N; i++) {
        if(i <= a[0]) D[i][0]+=1;
        for(int j = 2*i; j <= N; j+=i) {
            for(int k = 0; k < 19; k++) {
                D[j][k+1] += D[i][k];
                int t = max(g[i], g[j]-1);
                if(t >= k+1) D[j][0] -= D[i][k]*fac[t]*ifac[k+1]*ifac[t-(k+1)];
            }
        }
    }

    mi ans = 0;
    for(int i = 1; i <= a.back(); i++) {
        for(int k = 0; k <= min(19, n); k++) ans += D[i][k]*fac[n]*ifac[k]*ifac[n-k];
    }

    // for(int i = 1; i <= N; i++) {
    //     for(int k = 0; k < 20; k++) cout << i << " " << k << " " << D[i][k] << endl;
    // }

    cout << ans;

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