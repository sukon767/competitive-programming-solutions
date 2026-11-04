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
    ll n, K; cin >> n >> K;

    //2^k. probability of sortedness is (K-1+2^k choose K-1).
    //probability of emergent unsortedness is P(not sorted, sorted) + P(sorted, sorted but combine is bad.)
    //p(1-p) + 
    //1 ... a, b ... is (a-1 + (2^k-1) choose a-1)*sum(b < a) {(K-b+(2^k-1) choose K-b)}.

    vector<mi> in(K+1); in[0] = in[1] = 1;
    for(int i = 2; i <= K; i++) {
        in[i] = (-MOD/i)*in[MOD%i];
    }

    mi ans = 0;
    mi p2 = 1;
    mi denom = K;
    for(int k = 0; k < n; k++) {
        mi t = 0;
        vector<mi> a(K+1), suf(K+1);
        mi p = 1;
        a[1] = 1;
        for(int i = 2; i <= K; i++) {
            a[i] = a[i-1]*((i-1) + (p2-1))*in[i-1];
            p = p*((i-1) + (p2))*in[i-1];
        }
        suf = a;
        for(int i = K-1; i >= 0; i--) suf[i] += suf[i+1];
        t += p*(denom-p);
        denom = denom*denom;
        // cout << suf[1] << " " << suf[2] << endl;
        // cout << pre[0] << " " << pre[1] << endl;

        for(int i = 2; i <= K; i++) {
            //1...i, 1...K-i+2
            t += a[i]*suf[K-i+2];
        }
        // cout << t << endl;

        ans += t/denom*(n-k);
        p2 *= 2;
    }

    cout << ans;
}

//king of the sun o_O
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