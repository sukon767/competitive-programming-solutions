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
    ll n; ll k; cin >> n >> k;
    ll sn = sqrt(n);
    mi ans = 0;
    mi o6 = mi(1)/6;
    
    if(k > n) {ans += mi(k-n)*n; k = n;}

    //k = 0
    if(k > sn) {
        for(ll i = sn; i >= 1; i--) {
            ll a = n/i, b = max(sn, n/(i+1));
            // cout << i << " " << a << " " << b << endl;
            //count from a to b+1, n/x equals i.
            bool endi = false;
            if(k <= a) {endi = true; a = k;}
            ans += mi(a*(a+1)/2-b*(b+1)/2)*n - i*(mi(a)*(a+1)*(2*a+1) - mi(b)*(b+1)*(2*b+1))*o6;
            if(endi) break;
        }
    }

    //k = 1

    if(k > sn) {
        for(ll i = sn; i >= 1; i--) {
            ll a = n/i, b = max(sn, n/(i+1));
            //count from a to b+1, n/x equals i.
            bool endi = false;
            if(k <= a) {endi = true; a = k;}
            ans += mi(a-b)*i;
            if(endi) break;
        }
    }

    //rest

    // sum ((n//p^k) mod p)p^{logp(n)-k}
    for(ll i = 2; i <= min(k, n/i); i++) {
        ll nn = n, e = -1;
        vector<ll> dig;
        while(nn) {
            e++;
            dig.push_back(nn%i);
            nn/=i;
        }
        for(ll j = 0; j < dig.size(); j++) ans += dig[j]*pow(mi(i), e-j);
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