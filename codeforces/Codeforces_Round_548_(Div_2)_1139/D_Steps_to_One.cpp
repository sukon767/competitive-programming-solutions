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
    int m; cin >> m;
    vector<mi> E(m+1);
    vector<vector<int>> div(m+1);
    vector<int> mob(m+1); mob[1] = 1;

    for(int i = 1; i <= m; i++)
        for(int j = 2*i; j <= m; j+=i) mob[j] -= mob[i];

    for(int i = 1; i <= m; i++)
        for(int j = i; j <= m; j+=i) div[j].push_back(i);

    mi invm = mi(1)/m;
    for(int i = 2; i <= m; i++) {
        E[i]+=1;
        for(int d : div[i]) {
            if(d == i) continue;
            int n = m/d;
            int dc = i/d;
            ll s = 0;
            for(int dn : div[dc]) {
                // if(i == 2) cout << dn << " " << n << " " << dc << endl;
                 s += mob[dn]*n/dn;}
            E[i] += s*invm*E[d];
            // cout << i << " " << d << " " << s << endl;
        }
        E[i] *= mi(m)/(m-m/i);
        // cout << i << " " << E[i] << endl;
    }
    // cout << E[2] <<endl;

    mi ans = 0;
    for(int i = 1; i <= m; i++) ans += E[i];
    cout << ans*invm+1;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}