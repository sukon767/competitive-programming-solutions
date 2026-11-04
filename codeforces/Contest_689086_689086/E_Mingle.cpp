#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using v = vector<T>;
using ll = long long;
using dd = long double;
using int2 = pair<int, int>;
using ll2 = pair<ll, ll>;
using dd2 = pair<dd, dd>;

#define f first
#define s second
#define all(x) begin(x), end(x)
istream &__cin = cin;
#ifdef DEV_MODE
#include "debug.h"
__cinwrapper __cin_wrapper;
#define cin __cin_wrapper
#else
#define dbg(...)
#define dbg2d(...)
#define __tc
#endif

template <class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T, size_t N> istream &operator>>(istream &in, array<T, N> &a) {
  for (auto &x : a)
    in >> x;
  return in;
}
template <class T> istream &operator>>(istream &in, v<T> &v) {
  for (auto &x : v)
    in >> x;
  return in;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> v<T> vec(int n, T val) { return v(n, val); }
template <class... Ts> auto vec(int n, Ts... args) {
  return v(n, vec(args...));
}

/*
 _____________________________________
( Life gives life to life, and that's )
( what the ICPC is about.             )
(                                     )
( - Bill Poucher                      )
 -------------------------------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

const bool INTERACTIVE = false;
const bool MULTITEST = false;
/******************************************************************************/

#pragma region templates

namespace ops {
struct tag_ordering {};
struct tag_counting {};

template <class T> struct none {
  static T IDENTITY;
};
template <class T> T none<T>::IDENTITY = T();
template <class T> struct plus {
  static T IDENTITY;
  static T comb(T a, T b) { return a + b; }
};
template <class T> T plus<T>::IDENTITY = 0;
template <class T> struct times {
  static T IDENTITY;
  static T comb(T a, T b) { return a * b; }
};
template <class T> T times<T>::IDENTITY = 1;
template <class T> struct min {
  static T IDENTITY;
  static T comb(T a, T b) { return std::min(a, b); }
  operator tag_ordering() { return {}; };
};
template <class T> T min<T>::IDENTITY = std::numeric_limits<T>::max();
template <class T1, class T2> struct min<pair<T1, T2>> {
  static pair<T1, T2> IDENTITY;
  static pair<T1, T2> comb(pair<T1, T2> a, pair<T1, T2> b) {
    return std::min(a, b);
  }
  operator tag_ordering() { return {}; };
};
template <class T1, class T2>
pair<T1, T2> min<pair<T1, T2>>::IDENTITY = {
    std::numeric_limits<T1>::max(),
    std::numeric_limits<T2>::max(),
};
template <class T> struct max {
  static T IDENTITY;
  static T comb(T a, T b) { return std::max(a, b); }
  operator tag_ordering() { return {}; };
};
template <class T> T max<T>::IDENTITY = std::numeric_limits<T>::lowest();
template <class T1, class T2> struct max<pair<T1, T2>> {
  static pair<T1, T2> IDENTITY;
  static pair<T1, T2> comb(pair<T1, T2> a, pair<T1, T2> b) {
    return std::max(a, b);
  }
  operator tag_ordering() { return {}; };
};
template <class T1, class T2>
pair<T1, T2> max<pair<T1, T2>>::IDENTITY = {
    std::numeric_limits<T1>::lowest(),
    std::numeric_limits<T2>::lowest(),
};
template <class T> struct min_count {
  static pair<T, int> IDENTITY;
  static pair<T, int> comb(pair<T, int> a, pair<T, int> b) {
    if (a.f == b.f) {
      return {a.f, a.s + b.s};
    }
    return std::min(a, b);
  }
  operator tag_counting() { return {}; };
};
template <class T>
pair<T, int> min_count<T>::IDENTITY = {std::numeric_limits<T>::max(), 0};
template <class T> struct max_count {
  static pair<T, int> IDENTITY;
  static pair<T, int> comb(pair<T, int> a, pair<T, int> b) {
    if (a.f == b.f) {
      return {a.f, a.s + b.s};
    }
    return std::max(a, b);
  }
  operator tag_counting() { return {}; };
};
template <class T> struct gcd {
  static T IDENTITY;
  static T comb(T a, T b) { return std::gcd(a, b); }
};
template <class T> T gcd<T>::IDENTITY = 0;
template <class T> struct bit_xor {
  static T IDENTITY;
  static T comb(T a, T b) { return a ^ b; }
};
template <class T> T bit_xor<T>::IDENTITY = 0;
template <class T>
pair<T, int> max_count<T>::IDENTITY = {std::numeric_limits<T>::lowest(), 0};
template <class O> struct pair {
  typedef decltype(O::IDENTITY) T;
  static ::pair<T, T> IDENTITY;
  static ::pair<T, T> comb(::pair<T, T> a, ::pair<T, T> b) {
    return {O::comb(a.f, b.f), O::comb(a.s, b.s)};
  }
  operator tag_ordering() { return (tag_ordering)O(); }
};
template <class O>
::pair<decltype(O::IDENTITY), decltype(O::IDENTITY)> pair<O>::IDENTITY = {
    O::IDENTITY, O::IDENTITY};
}; // namespace ops

namespace upd {
struct none {
  static none IDENTITY;
  void composite(none){};
  template <class T, class U> void apply(T &, auto, auto, U) const {};
};
none none::IDENTITY;
template <class T> struct add {
  T data;
  static add IDENTITY;
  static add plus_eq(T val) { return {val}; }

  void composite(add other) { data += other.data; }

  void apply(T &val, auto l, auto r, ops::plus<T>) const {
    val += data * (r - l + 1);
  }
  void apply(T &val, auto, auto, ops::tag_ordering) const { val += data; }
  void apply(pair<T, int> &val, auto, auto, ops::tag_counting) const {
    val.f += data;
  }
  void apply(T &val, auto, auto, ops::none<T>) const { val += data; }
};
template <class T> add<T> add<T>::IDENTITY = {0};
template <class T> struct set {
  optional<T> data;
  static set IDENTITY;
  static set eq(T val) { return {val}; }

  void composite(set other) {
    if (other.data)
      data = other.data;
  }

  void apply(T &val, auto l, auto r, ops::plus<T>) const {
    if (data)
      val = data.value() * (r - l + 1);
  }
  void apply(T &val, auto l, auto r, ops::bit_xor<T>) const {
    if (data)
      val = ((r ^ l) & 1) ? 0 : data.value();
  }
  void apply(T &val, auto, auto, ops::tag_ordering) const {
    if (data)
      val = data.value();
  }
  void apply(pair<T, int> &val, auto l, auto r, ops::tag_counting) const {
    if (data) {
      val = {data.value(), r - l + 1};
    }
  }
  void apply(T &val, auto, auto, ops::none<T>) const {
    if (data)
      val = data.value();
  }
};
template <class T> set<T> set<T>::IDENTITY = {nullopt};
template <class T> struct add_set {
  bool set;
  T data;
  static add_set IDENTITY;
  static add_set plus_eq(T val) { return {false, val}; }
  static add_set eq(T val) { return {true, val}; }

  void composite(add_set other) {
    if (other.set) {
      data = other.data;
      set = true;
    } else {
      data += other.data;
    }
  }

  void apply(T &val, auto l, auto r, ops::plus<T>) const {
    if (set) {
      val = data * (r - l + 1);
    } else {
      val += data * (r - l + 1);
    }
  }
  void apply(T &val, auto, auto, ops::tag_ordering) const {
    if (set) {
      val = data;
    } else {
      val += data;
    }
  }
  void apply(pair<T, int> &val, auto l, auto r, ops::tag_counting) const {
    if (set) {
      val = {data, r - l + 1};
    } else {
      val.f += data;
    }
  }
  void apply(T &val, int, int, ops::none<T>) const {
    if (set) {
      val = data;
    } else {
      val += data;
    }
  }
};
template <class T> add_set<T> add_set<T>::IDENTITY = {false, 0};

template <class T> struct affine {
  T m, b;

  static affine IDENTITY;
  static affine times_eq(T val) { return {val, 0}; }
  static affine plus_eq(T val) { return {1, val}; }
  static affine eq(T val) { return {0, val}; }

  void composite(affine other) {
    m *= other.m;
    b = other.b + other.m * b;
  }

  void apply(T &val, auto l, auto r, ops::plus<T>) const {
    if (m != 1)
      val *= m;
    if (b != 0)
      val += b * (r - l + 1);
  }
  void apply(T &val, auto, auto, ops::tag_ordering) const {
#ifdef DEV_MODE
    assert(m >= 0);
#endif
    if (m != 1)
      val *= m;
    if (b != 0)
      val += b;
  }
  void apply(T &val, auto, auto, ops::none<T>) const {
    if (m != 1)
      val *= m;
    if (b != 0)
      val += b;
  }
};
template <class T> affine<T> affine<T>::IDENTITY = {1, 0};

template <class T> struct index_affine {
  T a, b, c;

  inline static index_affine IDENTITY = {1, 0, 0};
  static index_affine times_eq(T val) { return {val, 0, 0}; }
  static index_affine plus_eq(T val) { return {1, 0, val}; }
  static index_affine eq(T val) { return {0, 0, val}; }

  void composite(index_affine other) {
    a *= other.a;
    b = other.b + other.a * b;
    c = other.c + other.a * c;
  }

  void apply(T &val, auto l, auto r, ops::plus<T>) const {
    if (a != 1)
      val *= a;
    if (b != 0)
      val += b * (T)(l + r) * (r - l + 1) / 2;
    if (c != 0)
      val += c * (r - l + 1);
  }
  void apply(T &val, auto l, auto, ops::none<T>) const {
    if (a != 1)
      val *= a;
    if (c != 0)
      val += c * l;
    if (c != 0)
      val += c;
  }
};

template <class U> struct swap {
  bool enable;
  U left, right;

  static swap IDENTITY;
  static swap eq(auto val) { return {false, U::eq(val.f), U::eq(val.s)}; };
  static swap plus_eq(auto val) {
    return {false, U::plus_eq(val.f), U::plus_eq(val.s)};
  };
  static swap times_eq(auto val) {
    return {false, U::times_eq(val.f), U::times_eq(val.s)};
  };

  swap(bool enable, U left, U right)
      : enable(enable), left(left), right(right) {}
  swap() : swap(1, U::IDENTITY, U::IDENTITY) {}

  void composite(swap other) {
    if (other.enable)
      ::swap(left, right);
    enable ^= other.enable;
    left.composite(other.left);
    right.composite(other.right);
  }

  void apply(auto &val, int l, int r, auto op) const {
    if (enable)
      ::swap(val.f, val.s);
    left.apply(val.f, l, r, op);
    right.apply(val.s, l, r, op);
  }
};
template <class U>
swap<U> swap<U>::IDENTITY = {false, U::IDENTITY, U::IDENTITY};

template <class T> struct chmin {
  T val;

  inline static chmin IDENTITY = {numeric_limits<T>::max()};

  void composite(chmin other) { val = min(val, other.val); }

  void apply(T &val, auto, auto, ops::none<T>) const {
    val = min(val, this->val);
  }
};

}; // namespace upd

#define DEV_MODE_SEG_SUPPORT
template <class T, class Op> class seg {
  int n;
  v<T> data;

  void pull(int p) { data[p] = Op::comb(data[2 * p], data[2 * p + 1]); }

  class leaf_reference {
    seg &par;
    int p;
    char mutated = 0;
    T init;

  public:
    leaf_reference(seg &par, int p) : par(par), p(p + par.n) {}

    T const &operator*() const { return par.data[p]; }
    T const *operator->() const { return &par.data[p]; }
    T &operator*() { return par.data[p]; }
    T *operator->() { return &par.data[p]; }

    operator T const &() const { return par.data[p]; }
    operator T &() {
      if (!mutated) {
        mutated = 1;
        init = par.data[p];
      }

      return par.data[p];
    }
    T &operator=(T val) {
      mutated = 2;
      return par.data[p] = val;
    }
    ~leaf_reference() {
      if (mutated == 2 || (mutated == 1 && init != par.data[p])) {
        for (p >>= 1; p; p >>= 1)
          par.pull(p);
      }
    }
  };

public:
  typedef T value_type;
  seg(int n) : n(n), data(2 * n, Op::IDENTITY) {}
  seg() : seg(0) {}
  seg(v<T> const &vals) : n(vals.size()), data(2 * n) {
    copy(vals.begin(), vals.end(), data.begin() + n);
    for (int p = n - 1; p; p--)
      pull(p);
  }
  seg(int n, T def) : n(n), data(2 * n) {
    fill(data.begin() + n, data.end(), def);
    for (int p = n - 1; p; p--)
      pull(p);
  }

  int size() const { return n; }

  T comb(T l, T r) const { return Op::comb(l, r); }

  T operator()(int l, int r) const {
#ifdef DEV_MODE
    assert(l >= 0);
    assert(r < n);
    assert(l <= r);
#endif
    T ra = Op::IDENTITY, rb = Op::IDENTITY;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ra = Op::comb(ra, data[l++]);
      if (r & 1)
        rb = Op::comb(data[--r], rb);
    }
    return Op::comb(ra, rb);
  }

  leaf_reference operator[](int p) {
#ifdef DEV_MODE
    assert(p >= 0 && p < n);
#endif
    return leaf_reference(*this, p);
  }

  T const &operator[](int p) const {
#ifdef DEV_MODE
    assert(p >= 0 && p < n);
#endif
    return data[p + n];
  }
};

#pragma endregion templates
vector<vector<int>> st;
vector<vector<int>> arr;
int m;

struct garb {
  static v<int> IDENTITY;
  static v<int> comb(v<int> const &a, v<int> const &b) {
    v<int> c(m + 1);
    for (int i = 0; i <= m; i++)
      c[i] = b[a[i]];
    return c;
  }
};
v<int> garb::IDENTITY;

void comb(vector<int> &a, vector<int> &b, vector<int> &c) {
  for (int i = 0; i <= m; i++)
    c[i] = b[a[i]];
}

void solve() {
  int n;
  cin >> n >> m;
  v<int> a(n);
  cin >> a;
  garb::IDENTITY.resize(m + 1);
  iota(all(garb::IDENTITY), 0);
  auto _seg = vec(n - 1, m + 1, 0);

  for (int i = 0; i + 1 < n; i++) {

    for (int j = 0; j <= m; j++) {
      // j*a[i] -> ?*a[i+1]
      ll val = (ll)j * a[i];
      ll to = min(val / a[i + 1], (ll)m);
      _seg[i][j] = to;
    }
  }
  seg<v<int>, garb> seg(_seg);
  auto upd = [&](int i) {
    if (i < 0 || i >= n - 1)
      return;
    v<int> newv(m + 1);
    for (int j = 0; j <= m; j++) {
      // j*a[i] -> ?*a[i+1]
      ll val = (ll)j * a[i];
      ll to = min(val / a[i + 1], (ll)m);
      newv[j] = to;
    }
    seg[i] = newv;
  };
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      i--;

      a[i] = x;
      upd(i);
      upd(i - 1);
    } else {
      int l, r;
      ll p;
      cin >> l >> r >> p;
      l--, r--;

      if (l < r) {
        ll from = min((ll)m, p / a[l]);
        p = seg(l, r - 1)[from] * a[r];
      }
      dbg(p);

      cout << min(p * a[r], p - (p % a[r])) << '\n';
    }
  }
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "e.txt");
#else
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int t;
  if (MULTITEST)
    cin >> t;
  else
    t = 1;
  while (t--)
    __tc solve();

#ifdef DEV_MODE
  debug_exit(INTERACTIVE);
#endif
}
#ifdef DEV_MODE
#include "debug.cpp"
#endif
