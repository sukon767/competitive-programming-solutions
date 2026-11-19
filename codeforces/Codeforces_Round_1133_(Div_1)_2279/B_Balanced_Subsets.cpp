#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

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

//sukon always reads the entire problem statement.
void solve() {
    // 11011(10/01)
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> f(3*n+4);
    for(int &i : a) {
        cin >> i, i--;
        f[i] = 1;
    }

    vector<mi> dp(16);
    mi ans = n + (mi)n*(n-1)/2;
    for(int i = 0; i < 3*n; i++) {
        //add i+3
        if(f[i+3]) {
            for(int i = 0; i < 8; i++) {
                dp[i | (1<<3)]+=dp[i];
            }
        }
        
        //add in new at ur index
        if(f[i]) {
            for(int j = 0; j < 3; j++) {
                int b1 = 1+(j+1)%3, b2 = 1+(j+2)%3;
                if(f[i+b1] && f[i+b2]) dp[1 | (1<<b1) | (1<<b2)]+=1;
            }
        }

        vector<mi> nxt(16);
        //transition valid
        for(int i = 0; i < 16; i++) {
            if((i&1) && __builtin_popcount(i)==3) {
                ans += dp[i];
                nxt[i>>1] += dp[i];
            } else if(!(i&1)) nxt[i>>1] += dp[i];
        }

        dp = nxt;
    }

    cout << ans;
}

//king of the sun o_O
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