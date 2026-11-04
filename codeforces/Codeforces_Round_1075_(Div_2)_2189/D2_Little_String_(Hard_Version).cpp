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
    int n, c; cin >> n >> c;
    string s;
    cin >> s;
    if(s[0] == '0' || s[n-1] == '0' || c == 1) {cout << -1; return;}

    mi ans = 2;
    for(int i = 1; i <= n-2; i++) {
        if(s[i] == '1') {
            ans *= 2;
            c /= gcd(c, 2);
        }
        else if(s[i] == '0') {
            ans *= i;
            c /= gcd(c, i);
        }
        // cout << c << endl;
    }
    c /= gcd(2, c);

    if(c == 1) {cout << -1; return;}

    int bit = 0;
    for(int b = 0; b < 31; b++) {
        if(c&(1<<b)) {bit = b; break;}
    }

    for(int i = 2; i <= n-2; i+=2) {
        if(s[i] == '?') {
            if(c == 2) {cout << -1; return;}
            c /= gcd(c, 2); ans *= 2;
        }
    }
    for(int i = (n-1)/2*2-1; i >= 3; i-=2) {
        if(s[i] == '?') {
            if(c == 2) ans *= i;
            else {c /= gcd(c, 2); ans *= 2;}
        }
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