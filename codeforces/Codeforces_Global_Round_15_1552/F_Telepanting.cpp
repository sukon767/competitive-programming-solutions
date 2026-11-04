#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

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
    string s;
    vector<vector<int>> th(n, vector<int>(3));
    for(auto &i : th) {
        cin >> i[0] >> i[1];
        int b; cin >> b;
        s.push_back(b + '0');
    }
    
    for(int i = 0; i < n; i++) th[i][2] = i;

    vector<mi> ones(n); ones[0] = th[0][0]-th[0][1];
    for(int i = 1; i < n; i++) {
        
        ones[i] = th[i][0]-th[i][1] + ones[i-1];
        auto it = lower_bound(th.begin(), th.end(), vector<int>{th[i][1], 0, 0});
        if(it != th.begin()) {
            ones[i] -= ones[(*prev(it))[2]];
        }
        ones[i] += ones[i-1];
    }

    mi ans = th.back()[0]+1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ans += ones[i];
            if(i) ans -= ones[i-1];
        } 
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */