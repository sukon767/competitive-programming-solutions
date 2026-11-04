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
  int n;
  cin >> n;
  vector<vector<int>> ret(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i < j)
        ret[i][j] = 4;
      else if (i > j)
        ret[i][j] = 2;
      else
        ret[i][j] = (i % 2 == 0) ? 2 : 3;
  if (n % 2 == 1) {
    for (int i = 0; i < n; i++) {
      ret[i][n - 1] = 1;
      ret[n - 1][i] = 1;
    }
    ret[n - 1][n - 2] = 2;
  }
  // dbg2d(ret);
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < n; j++)
      x += ret[i][j];
    s.insert(x);
    x = 0;
    for (int j = 0; j < n; j++)
      x += ret[j][i];
    s.insert(x);
  }
  assert(s.size() == 2 * n);
  for (auto &a : ret) {
    for (int i : a)
      cout << i;
    cout << "\n";
  }
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "l.txt");
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
