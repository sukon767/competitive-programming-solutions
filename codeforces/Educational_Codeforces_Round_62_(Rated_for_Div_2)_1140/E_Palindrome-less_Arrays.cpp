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
    int n, k; cin >> n >> k;
    mi ans = 1;
    vector<int> a(n); for(int& i : a) cin >> i;
    for(int i = 0; i+2 < n; i++) {
        if(a[i] != -1 && a[i] == a[i+2]) {cout << 0; return;}
    }


    vector<mi> S(n+1), D(n+1), k1p(n+1);
    D[0] = k1p[0] = 1;
    for(int i = 1; i <= n; i++) {
        S[i] = D[i-1]*(k-1);
        D[i] = S[i-1] + D[i-1]*(k-2);
        k1p[i] = k1p[i-1]*(k-1);
    }

    for(int j = 0; j < 2; j++) {
        int prev = j-2;
        int i = j;
        while(i < n) {

            if(a[i] != -1) {
                int b = (i-prev)/2 -1;
                if(b > 0) {
                    if(prev < 0) {
                        ans *= k1p[b];
                    } else if(a[prev] == a[i]) {
                        ans *= S[b];
                    } else {
                        ans *= D[b];
                    }
                }
                prev = i;
            }
            i += 2;
        }

        int b = (i-prev)/2 -1;
        if(b > 0) {
            if(prev < 0) {
                ans *= k*k1p[b-1];
            } else {
                ans *= k1p[b];
            }
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */