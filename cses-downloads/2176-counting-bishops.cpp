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
    int n, k; cin >> n >> k;
    if(n == 1)  {cout << 1; return;}
    if(k > 2*n-2)   {cout << 0; return;}
    //max is 2n-2
    vector<vector<mi>> dpo(n/2 + n%2, vector<mi>(2*n-1)), dpe(n/2 + 1, vector<mi>(2*n-1));
    // cout << "asdf\n";
    dpo[0][0] = 1; dpo[0][1] = 2;
    for(int i = 1; i < n/2 + n%2; i++)
        for(int j = 0; j <= 2*n-2; j++) {
            dpo[i][j] += dpo[i-1][j];
            if(i == n/2) {
                if(j>0) dpo[i][j] += dpo[i-1][j-1]*(2*i+1 - (j-1));
                continue;
            }
            if(j>0) dpo[i][j] += dpo[i-1][j-1]*(2*i+1 - (j-1))*2;
            if(j>1) dpo[i][j] += dpo[i-1][j-2]*(2*i+1 - (j-2))*(2*i+1 - (j-1));
        }
    // cout << "asdf\n";
    dpe[0][0] = 1;
    for(int i = 1; i <= n/2; i++)
        for(int j = 0; j <= 2*n -2; j++) {
            dpe[i][j] += dpe[i-1][j];
            if(i == n/2 && !(n%2)) {
                if(j>0) dpe[i][j] += dpe[i-1][j-1]*(2*i - (j-1));
                continue;
            }
            if(j>0) dpe[i][j] += dpe[i-1][j-1]*(2*i - (j-1))*2;
            if(j>1) dpe[i][j] += dpe[i-1][j-2]*(2*i - (j-2))*(2*i - (j-1));
        }
    // cout << "asdf\n";
    mi ans = 0;
    for(int i = 0; i <= k; i++) {
        ans += dpo.back()[i]*dpe.back()[k-i];
    }
    // for(int j = 0; j < 2*n-2; j++) {
    //     for(int i = 0; i <= n/2; i++)
    //         cout << dpe[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << '\n';
    cout << ans;
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
