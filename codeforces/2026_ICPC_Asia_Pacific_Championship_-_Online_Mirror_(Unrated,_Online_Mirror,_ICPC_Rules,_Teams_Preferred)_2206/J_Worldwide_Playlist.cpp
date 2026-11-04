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
( She Gozinta on my Chain till i OEIS )
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

#pragma endregion templates

void solve() {
  int n, d;
  cin >> n >> d;
  v<int> a(n);
  cin >> a;
  v<int> b(n);
  cin >> b;

  for (auto &x : a)
    x--;
  for (auto &x : b)
    x--;

  v<int> posa(n), posb(n);
  for (int i = 0; i < n; i++) {
    posa[a[i]] = i;
    posb[b[i]] = i;
  }

  auto contrib = [&](int i) {
    if (i == 0) {
      return posa[b[i]];
    } else if (i < n) {
      return (posa[b[i]] - posa[b[i - 1]] + n) % n - 1;
    } else {
      return 0;
    }
  };

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += contrib(i);
    dbg(contrib(i));
  }

  cout << ans << '\n';
  d--;
  while (d--) {
    int c, x, y;
    cin >> c >> x >> y;
    x--, y--;

    array<int, 4> upd;
    if (c == 1) {
      upd = {posb[a[x]], posb[a[x]] + 1, posb[a[y]], posb[a[y]] + 1};
    } else {
      upd = {x, x + 1, y, y + 1};
    }
    sort(all(upd));
    int end = unique(upd.begin(), upd.end()) - begin(upd);

    for (int i = 0; i < end; i++) {
      dbg(upd[i], contrib(upd[i]));
      ans -= contrib(upd[i]);
    }

    if (c == 1) {
      swap(posa[a[x]], posa[a[y]]);
      swap(a[x], a[y]);
    } else {
      swap(posb[b[x]], posb[b[y]]);
      swap(b[x], b[y]);
    }
    dbg(a, b);

    for (int i = 0; i < end; i++) {
      dbg(upd[i], contrib(upd[i]));
      ans += contrib(upd[i]);
    }

    cout << ans << '\n';
  }
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "j.txt");
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
