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
    vector<int> a(n), b(n); for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;

    if(n == 1) {
        cout << 0; return;
    }

    vector<pair<int, int>> bs;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            bs.push_back({b[i], b[j]});
            bs.push_back({b[j], b[i]});
        }
    }

    sort(bs.begin(), bs.end(), [](auto& x, auto& y) {
        return (ll)x.first*y.second > (ll)x.second*y.first;
    });

    mi ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            //bsearch
            int l = -1, r = sz(bs)-1;
            while(l < r) {
                int m = (l+r+1)>>1;
                if((ll)a[i]*bs[m].first > (ll)a[j]*bs[m].second) {
                    l = m;
                } else r = m-1;
            }
            ans += l+1;

            // cout << a[i] << " " << a[j] << " " << l+1 << endl;
        }
    }

    cout << ans/((mi)n*(n-1));
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