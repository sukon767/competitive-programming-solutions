#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

template <class T> using v = vector<T>;

// using the Extended Euclidean Algorithm to compute modular inverse
// comparison to other methods (local runtime for 10^7 inverse calculations)
//
// euclidean division:           1.21s
// fermat's little theorem:      0.95s
// extended euclidean algorithm: 0.63s

// NOTE: / and /= assume the divisor is coprime to MOD and take O(log MOD) time
//       >> assumes that the input is in the interval [0, MOD)
const int MOD = 998244353;

template <const int MOD> class modint {
  int val;

public:
  constexpr modint() : val(0) {}
  constexpr modint(int v) : val(v % MOD) {
    if (val < 0)
      val += MOD;
  }
  constexpr modint(ll v) : val(v % MOD) {
    if (val < 0)
      val += MOD;
  }
  constexpr modint(unsigned long long v) : val(v % MOD) {}
  constexpr modint(unsigned long v) : val(v % MOD) {}

  constexpr explicit operator ll() const { return val; }
  constexpr explicit operator int() const { return val; }

  constexpr friend modint &operator+=(modint &a, modint b) {
    a.val += b.val;
    if (a.val >= MOD)
      a.val -= MOD;
    return a;
  }
  constexpr friend modint &operator-=(modint &a, modint b) {
    a.val -= b.val;
    if (a.val < 0)
      a.val += MOD;
    return a;
  }
  constexpr friend modint &operator*=(modint &a, modint b) {
    a.val = ((ll)a.val * b.val) % MOD;
    return a;
  }
  constexpr friend modint &operator/=(modint &a, modint b) {
    int x = 1, y = 0;
    int x1 = 0, y1 = 1;
    int a1 = b.val, b1 = MOD;

    while (b1) {
      int q = a1 / b1;

      int nb1 = a1 - q * b1;
      int nx1 = x - q * x1;
      int ny1 = y - q * y1;

      x = x1;
      y = y1;
      a1 = b1;
      b1 = nb1;
      x1 = nx1;
      y1 = ny1;
    }

    return a *= x;
  }
  constexpr friend modint &operator++(modint &x) { return x += 1; }
  constexpr friend modint &operator--(modint &x) { return x -= 1; }
  constexpr friend modint operator++(modint &x, int) {
    modint tmp = x;
    ++x;
    return tmp;
  }
  constexpr friend modint operator--(modint &x, int) {
    modint tmp = x;
    --x;
    return tmp;
  }
  constexpr friend modint operator-(modint x) {
    if (x == 0)
      return x;
    return {-x.val + MOD};
  }

  constexpr friend modint operator+(modint a, modint b) { return a += b; }
  constexpr friend modint operator-(modint a, modint b) { return a -= b; }
  constexpr friend modint operator*(modint a, modint b) { return a *= b; }
  constexpr friend modint operator/(modint a, modint b) { return a /= b; }

  friend istream &operator>>(istream &in, modint &x) { return in >> x.val; }
  friend ostream &operator<<(ostream &out, modint x) { return out << x.val; }

  constexpr friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }
  constexpr friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

  constexpr static modint pow(modint a, unsigned long long b) {
    modint acc = 1;
    while (b) {
      if (b & 1)
        acc *= a;
      a *= a;
      b >>= 1;
    }

    return acc;
  }
  constexpr friend modint pow(modint a, unsigned long long b) {
    return modint::pow(a, b);
  }

  static v<modint> fac, ifac;
  static void gen_fac(int n) {
    int old = fac.size();
    if (old < n + 1) {
      fac.resize(n + 1);
      for (int i = old; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
      }
    }
  }
  static void gen_ifac(int n) {
    int old = ifac.size();
    if (old < n + 1) {
      ifac.resize(n + 1);
      for (int i = old; i <= n; i++) {
        ifac[i] = ifac[i - 1] / i;
      }
    }
  }
  static void gen_facs(int n) {
    gen_fac(n);
    gen_ifac(n);
  }
  static modint c(int n, int k) {
    if (k > n)
      return 0;
#ifdef DEV_MODE
    assert(n < (int)fac.size());
    assert(n < (int)ifac.size());
#endif
    return fac[n] * ifac[k] * ifac[n - k];
  }
  static modint p(int n, int k) {
    if (k > n)
      return 0;
#ifdef DEV_MODE
    assert(n < (int)fac.size());
    assert(n < (int)ifac.size());
#endif
    return fac[n] * ifac[n - k];
  }
};
typedef modint<MOD> mint;
template <const int MOD> v<modint<MOD>> modint<MOD>::fac = {1};
template <const int MOD> v<modint<MOD>> modint<MOD>::ifac = {1};
auto &fac = mint::fac, &ifac = mint::ifac;
using mint2 = pair<mint, mint>;


template <class T> using v = vector<T>;

// 3 is the primitive root of 998244353

const mint ROOT = 15311432;     // 2^23-th principal root of unity mod 998244353
const mint ROOT_M1 = 469870224; // modular inverse of ROOT
const int BASE = 23;
// NTT and inverse NTT
void ntt(v<mint> &a, bool inv) {
#ifdef DEV_MODE
  assert(a.size() == (1 << __lg(a.size())));
#endif
  for (int i = 1, j = 0; i < a.size(); i++) {
    int bit = a.size() >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;

    if (i < j)
      swap(a[i], a[j]);
  }

  for (int n = 2; n <= a.size(); n <<= 1) {
    mint wb = inv ? ROOT_M1 : ROOT;
    for (int i = n; i < (1 << BASE); i <<= 1) {
      wb *= wb;
    }
    for (int i = 0; i < a.size(); i += n) {
      mint w = 1;
      for (int j = 0; j < n / 2; j++) {
        mint u = a[i + j], v = a[i + j + n / 2] * w;
        a[i + j] = u + v;
        a[i + j + n / 2] = u - v;
        w *= wb;
      }
    }
  }
  if (inv) {
    mint ni = (mint)1 / a.size();
    for (mint &x : a)
      x *= ni;
  }
}
void ntt(v<mint> &a) { ntt(a, false); }
void intt(v<mint> &a) { ntt(a, true); }

v<mint> conv_nt(v<mint> a, v<mint> b) {
  int final_sz = a.size() + b.size() - 1;
  int N = 1 << (32 - __builtin_clz(a.size() + b.size()));
  a.resize(N);
  b.resize(N);

  ntt(a);
  ntt(b);
  for (int i = 0; i < N; i++) {
    a[i] *= b[i];
  }
  intt(a);
  a.resize(final_sz);
  return a;
}
 
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> f(n+1);
    vector<vector<int>> fac(n+1);
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j+=i) fac[j].push_back(i);

    for(int i = 1; i < n; i++) {
        if(s[i-1] == '0') continue;
        if(s[i] != '0') continue;
        f[1] += int(s[i-1]) - int('0');
    }

    for(int i = 2; i <= n; i++) {
        if(s[i-1] == '0') continue;
        if(s[i-2] != '0') continue;
        f[1] += int(s[i-1]) - int('0');
    }

        // cout << "asdf" << endl;

    for(int i = 2; i <= n; i++) f[i] += f[i-1];

    for(int i = 1; i < n; i++) {
        if(s[i-1] == '0') continue;
        if(s[i] != '0') continue;
        // if i == 0 mod w
        for(int d : fac[i]) f[d] -= int(s[i-1]) - int('0');
    }

    for(int i = 2; i <= n; i++) {
        if(s[i-1] == '0') continue;
        if(s[i-2] != '0') continue;
        // if i == 1 mod w
        for(int d : fac[i-1]) f[d] -= int(s[i-1]) - int('0');
    }

    // cout << "asdf" << endl;

    vector<mint> a(n+1), b(n);

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') a[n-i]++;
        else {b[i] += int(s[i]) - int('0');}
    }
    // cout << "asdf" << endl;
    vector<mint> c = conv_nt(a, b);
    // cout << "asdf" << endl;
    for(int i = n+1; i < c.size(); i++) {
        f[i-n] += ll(c[i]);
    }

    a.assign(n, 0), b.assign(n, 0);

        // cout << "asdf" << endl;


    for(int i = 0; i < n; i++) {
        if(s[i] == '0') a[n-i]++;
        else {b[i] += int(s[i]) - int('0');}
    }
    c = conv_nt(a, b);
    for(int i = 0; i < n; i++) {
        f[abs(i-n)] += ll(c[i]);
    }

    sort(f.begin(), f.end());
    cout << f[n+1-k];

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