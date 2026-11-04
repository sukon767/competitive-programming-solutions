#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

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

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    mi ans = 1;
    vector<mi> fac(n+1), ifac(n+1), p2(n+1); fac[0] = ifac[0] = ifac[1] = fac[1] = p2[0] = 1; p2[1]=2;
    for(int i = 2; i <= n; i++) {
        p2[i] = p2[i-1]*2;
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[MOD%i]*(-MOD/i);
    }
    for(int i = 1; i <= n; i++) ifac[i] *= ifac[i-1];

    vector<ll> pre(n+1), suf(n+1);
    partial_sum(a.begin(), a.end(), pre.begin()+1); pre.push_back(pre.back());
    reverse(a.begin(), a.end()); partial_sum(a.begin(), a.end(), suf.begin()+1); suf.push_back(suf.back()); reverse(suf.begin(), suf.end()); 

    bool fir = 1;
    int l = 0, r = n+1;
    while(l <= r) {
        while(r > 0 && suf[r] < pre[l]) r--;
        if(l >= r) break;
        if(pre[l]==suf[r]) {
            pair<int, int> rs = {1, 1};
            if(fir) {rs = {0, 0}; fir = 0;}
            while(l < n && pre[l+1]==pre[l]) {l++; rs.first++;}
            while(r > 1 && suf[r-1]==suf[r]) {r--; rs.second++;}
            // cout << l << " " << r << " " << rs.first << " " << rs.second << " " << pre[2] << endl;
            if(l >= r) ans *= p2[min(rs.first, n-1)];
            else ans *= fac[rs.first+rs.second]*ifac[rs.first]*ifac[rs.second];
        }
        l++;
    }
    cout << ans;
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