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
    int n, m; cin >> n >> m;
    vector<int> f(61);
    for(int i = 0; i < n; i++) {
        int c; cin >> c; f[c]++;
    }

    int maxN = 67;
    vector<mi> in(maxN+1), p2(n+m+1);
    in[0] = in[1] = p2[0] = 1;
    for(int i = 2; i <= maxN; i++) {in[i] = (-MOD/i)*in[MOD%i];}
    for(int i = 1; i <= n+m; i++) p2[i] = p2[i-1]*2;

    int cur = n;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        if(t == 1) {int c; cin >> c; f[c]++; cur++;}
        else if(t == 2) {int c; cin >> c; f[c]--; cur--;}
        else {
            ll x; cin >> x;

            vector<int> pre(61); pre[0] = f[0];
            for(int i = 1; i <= 60; i++) pre[i] = pre[i-1]+f[i];

            int bit = 60, xbit = 60;
            while(!(x >> xbit & 1)) {bit--; xbit--; continue;}
            //bit is needed bit, xbit is contribution

            vector<int> cnt(61);
            mi precont = 1, ans = 0;

            while(xbit >= 0) {
                ans += precont*p2[bit ? pre[bit-1] : 0];

                //if we cant take the needed bit, we can just count everything and exit
                if(cnt[bit] >= f[bit]) break;

                //otherwise add such bit and update cnt and precont
                precont *= f[bit]-cnt[bit];
                cnt[bit]++; precont *= in[cnt[bit]];

                //find next bit
                xbit--;
                while(xbit >= 0 && !(x >> xbit & 1)) {
                    xbit--; bit--;
                }
            }

            // cout << cur << " " << ans << endl;
            cout << p2[cur] - ans << "\n";
        }
    }
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