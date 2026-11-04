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
    int k; cin >> k;
    vector<int> p(1<<k);
    mi ans = 1;
    for(int &i : p) cin >> i;
    vector<mi> fac((1<<k)+1); fac[0]=1;
    for(int i = 1; i <= 1<<k; i++) fac[i] = fac[i-1]*i;

    for(int i = k-1; i >= 0; i--) {
        vector<int> a(1<<i);
        int c = (1<<i);
        for(int j = 0; j < 1<<i; j++) {
            bool s = false;
            int t = 0;
            int ind = -1;
            for(int r = 0; r < 1<<(k-i); r++) {
                if((1<<i) < p[j*(1<<(k-i)) + r] && p[j*(1<<(k-i)) + r] <= (1<<(i+1))) {
                    if(a[j]) {cout << 0; return;}
                    a[j] = p[j*(1<<(k-i)) + r]; c--; s = true;
                } else if(!s && p[j*(1<<(k-i)) + r] == -1) {t++; ind = j*(1<<(k-i)) + r;}
            }
            if(!s)  {
                if(ind == -1) {cout << 0; return;}
                ans *= t; p[ind] = 0; 
            }

        }
        ans *= fac[c];
        // cout << i << " " << ans << endl;
    }

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