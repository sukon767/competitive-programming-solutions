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
 _______________________________________
( If you don't fail at least 90% of the )
( time, you're not aiming high enough.  )
(                                       )
( - Alan Kay                            )
 ---------------------------------------
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

#pragma endregion templates

void solve() {
  int k;
  cin >> k;
  v<int> a(1 << k);
  cin >> a;

  // v<ll> dp(k + 1);
  ll ans0 = 0, ans1 = 0;

  for (int i = 0; i < k; i++) {
    int sz = (1 << i);
    for (int l = 0; l < (1 << k); l += (2 << i)) {
      int m = l + (1 << i);
      int r = m + (1 << i);

      v<int> res;

      int lp = 0, rp = 0;
      while (lp < sz || rp < sz) {
        int ld = 0, rd = 0;
        int tv;
        if (lp == sz)
          tv = a[m + rp];
        else if (rp == sz)
          tv = a[l + lp];
        else
          tv = min(a[l + lp], a[m + rp]);

        while (lp + ld < sz && a[l + lp + ld] == tv)
          ld++;
        while (rp + rd < sz && a[m + rp + rd] == tv)
          rd++;

        ans0 += (ll)ld * (sz - rp - rd);
        ans1 += (ll)rd * (sz - lp - ld);
        for (int i = 0; i < ld + rd; i++)
          res.push_back(tv);
        lp += ld;
        rp += rd;
      }

      copy(all(res), begin(a) + l);
    }
  }

  ll ans = (ans0 + ans1) << (k - 1);
  cout << ans << '\n';
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "n.txt");
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
