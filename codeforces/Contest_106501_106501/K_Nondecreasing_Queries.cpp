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
#define compareby(x)                                                           \
  [&](auto ___i, auto ___j) {                                                  \
    auto ___get = [&](auto i) { return x; };                                   \
    return ___get(___i) < ___get(___j);                                        \
  }
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
( She Gozinta on my Chain till i OEIS )
 -------------------------------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

const bool INTERACTIVE = true;
const bool MULTITEST = false;
/******************************************************************************/

#pragma region templates

#pragma endregion templates

void solve() {
  int n;
  cin >> n;

  auto qry = [](int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    bool x;
    cin >> x;
    return x;
  };

  if (qry(1, 1)) {
    cout << "! 1" << endl;
    return;
  }

  int len = 1;
  int p = 2;
  while (true) {
    int left = p;
    int right = p + len - 1;
    if (right > n) {
      left -= right - n;
      right = n;
    }
    if (qry(left, right)) {
      // do stuff
      int lo = p;
      int hi = min(n, p + len - 1);
      while (lo < hi) {
        int mid = (lo + hi) >> 1;

        if (qry(mid - len + 1, mid)) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }

      cout << "! " << lo << endl;
      return;
    } else {
      p += len;
      len *= 2;
    }
  }
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "k.txt");
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
