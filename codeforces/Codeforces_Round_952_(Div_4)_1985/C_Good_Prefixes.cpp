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
 __________________________
( i hate beginners         )
(                          )
( how come they arent good )
 --------------------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

const bool INTERACTIVE = false;
const bool MULTITEST = true;
/******************************************************************************/

#pragma region templates

template <class T, class Op = plus<T>, class Inv = minus<T>> class psum {
#ifdef DEV_MODE
  bool summed = 0;
#endif
  v<T> vals;
  Op op;
  Inv inv;

  class value_reference {
    psum &par;
    int p;
    T init, val;

  public:
    value_reference(psum &par, int p) : par(par), p(p) {
      init = val = par.vals[p];
    };
    ~value_reference() {
      if (val != init) {
#ifdef DEV_MODE
        assert(!par.summed);
#endif
        par.vals[p] = val;
      }
    };
    operator T const &() const { return val; }
    operator T &() { return val; }
    T &operator=(T val) { return this->val = val; }
  };

public:
  struct update_type {
    T v;
    static update_type plus_eq(T v) { return {v}; }
  };

private:
  class range_reference {
    psum &par;
    int l, r;

  public:
    range_reference(psum &par, int l, int r) : par(par), l(l), r(r) {};
    operator T() {
#ifdef DEV_MODE
      assert(par.summed);
#endif
      return l ? (par.inv(par.vals[r], par.vals[l - 1])) : par.vals[r];
    }
    void upd(update_type u) { *this += u.v; }
    void operator++() { *this += 1; }
    void operator++(int) { *this += 1; }
    void operator--() { *this -= 1; }
    void operator--(int) { *this -= 1; }
    void operator+=(T val) {
#ifdef DEV_MODE
      assert(!par.summed);
#endif
      par.vals[l] = par.op(par.vals[l], val);
      if (r + 1 < (int)par.size()) {
        par.vals[r + 1] = par.inv(par.vals[r + 1], val);
      }
    }
    void operator-=(T val) {
#ifdef DEV_MODE
      assert(!par.summed);
#endif
      par.vals[l] = par.inv(par.vals[l], val);
      if (r + 1 < (int)par.size()) {
        par.vals[r + 1] = par.op(par.vals[r + 1], val);
      }
    }
  };

public:
  typedef T value_type;
  psum(int n, Op op, Inv inv) : vals(n), op(op), inv(inv) {};
  psum(int n) : psum(n, Op(), Inv()) {};
  psum(v<T> vals, Op op, Inv inv) : vals(vals), op(op), inv(inv) {};
  psum(v<T> vals) : psum(vals, Op(), Inv()) {};

  T comb(T a, T b) { return op(a, b); }

  void sum() {
#ifdef DEV_MODE
    assert(!summed);
    summed = 1;
#endif
    for (int i = 1; i < size(); i++) {
      vals[i] += vals[i - 1];
    }
  }

  value_reference operator[](int p) {
#ifdef DEV_MODE
    assert(p >= 0 && p < size());
#endif
    return value_reference(*this, p);
  }

  range_reference operator()(int l, int r) {
#ifdef DEV_MODE
    assert(l >= 0);
    assert(r < size());
    assert(l <= r);
#endif
    return range_reference(*this, l, r);
  }

  int size() { return vals.size(); }
};

#pragma endregion templates

void solve() {
  int n;
  cin >> n;
  v<ll> a(n);
  cin >> a;

  ll sum = 0;
  set<ll> has;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    has.insert(a[i]);
    if (sum % 2 == 0 && has.count(sum / 2)) {
      ans++;
    }
  }

  cout << ans << '\n';
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "cf.txt");
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
