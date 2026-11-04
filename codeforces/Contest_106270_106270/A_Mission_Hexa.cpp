#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

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

vector<mi> fac, ifac;
vector<ll> phi;

//sukon always reads the entire problem statement.
void solve() {
    ll n, k; cin >> n >> k;
    
    mi s = phi[n];
    ll layer = 1;
    ll on = 1;

    ll lo = 1, hi = n;
    while(lo < hi) {
        ll m = (lo+hi+1)>>1;
        ll onm = 1 + 3*(m)*(m-1);
        if(onm <= k) {lo = m; layer = m; on = onm;}
        else hi = m-1;
    }

    ll r = (k-on)%layer;
    cout << s*6 << " " << (fac[layer]*ifac[r]*ifac[layer-r]);
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1e6;
    fac = ifac = vector<mi>(N+1);
    phi = vector<ll>(N+1); iota(all(phi), 0LL);

    fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
    for(int i = 2; i <= N; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = (-MOD/i)*ifac[MOD%i];
    }
    for(int i = 1; i <= N; i++) ifac[i] *= ifac[i-1];

    for(int i = 2; i <= N; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= N; j+=i) phi[j] -= phi[j]/i;
        }
    }
    partial_sum(all(phi), phi.begin());

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