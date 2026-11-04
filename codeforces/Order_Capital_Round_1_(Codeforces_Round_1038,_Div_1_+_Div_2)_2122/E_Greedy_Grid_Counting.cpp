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
    ll fac = 1;
    int tt; cin >> tt; if(tt==-1) fac*=k;
    vector<int> a(n-1), b(n-1); for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    cin >> tt; if(tt==-1) fac*=k;

    vector<mi> suf(k+1); suf[0]=1;
    for(int i = n-2; i >= 0; i--) {
        
        vector<int> lis(2*k-1);
        if(a[i]==-1 && b[i]==-1) {
            for(int j = 0; j < 2*k-1; j++) lis[j] = k - abs((k-1) - j);
        } else if(a[i]!=-1 && b[i]!=-1) {
            lis[k-1+a[i]-b[i]]=1;
        } else if(a[i]==-1) {
            for(int j = k-1-b[i]+1; j <= k-1-b[i]+k; j++) lis[j]=1;
        } else {
            for(int j = k-1+a[i]-k; j <= k-1+a[i]-1; j++) lis[j]=1;
        }

        vector<mi> t(k+1);
        for(int j = 0; j <= k; j++) {
            for(int l = -(k-1); l <= min(-1, -j); l++) {
                t[0]+=suf[j]*lis[(k-1)+l];
            }
            for(int l = 0; l <= k-1; l++) {
                t[min(k, j+l)]+=suf[j]*lis[(k-1)+l];
            }
        }

        suf = t;
    }

    cout << accumulate(suf.begin(), suf.end(), (mi)0)*fac;
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