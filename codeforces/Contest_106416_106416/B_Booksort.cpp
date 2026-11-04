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
const bool MULTITEST = false;
/******************************************************************************/

#pragma region templates

#pragma endregion templates

void solve() {
  int n;
  cin >> n;
  v<int> a(n);
  cin >> a;

  v<int2> ops;
  auto op = [&](int i, int j) {
    int s = a[i] + a[j];
    ops.push_back({i + 1, j + 1});

    a[i] = s / 2;
    a[j] = (s + 1) / 2;
  };

  v<int> idx(n);
  iota(all(idx), 0);
  for (int i = 0; i < 20; i++) {
    sort(all(idx), [&](int i, int j) {
      return make_pair(a[i], -i) < make_pair(a[j], -j);
    });

    int l = 0;
    int r = n - 1;
    while (l < r) {
      op(min(idx[l], idx[r]), max(idx[l], idx[r]));
      l++, r--;
    }
    dbg(a);
  }

  assert(is_sorted(all(a)));
  assert(ops.size() <= 1e5);

  cout << ops.size() << '\n';
  for (auto [i, j] : ops)
    cout << i << ' ' << j << '\n';
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "b.txt");
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
