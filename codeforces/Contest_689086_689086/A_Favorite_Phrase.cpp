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

#pragma endregion templates

void solve() {
  int n;
  cin >> n;

  while (n) {
    for (int i = n; i >= 1; i--) {
      if (i * (i + 1) / 2 <= n) {
        for (int j = 0; j < i; j++)
          cout << 'a';
        cout << ' ';
        n -= i * (i + 1) / 2;
        break;
      }
    }
  }

  // vector<vector<int>> dp(n + 1);
  // for (int i = 1; i <= n; i++) {
  //   if (i * (i + 1) / 2 <= n)
  //     dp[i * (i + 1) / 2].push_back(i);
  // }

  // for (int i = 1; i <= n; i++) {
  //   if (dp[i].size()) {
  //     for (int j = 1; j <= n; j++) {
  //       if (j * (j + 1) / 2 + i <= n) {
  //         if (dp[i + j * (j + 1) / 2].size() == 0) {
  //           dp[i + j * (j + 1) / 2] = dp[i];
  //           dp[i + j * (j + 1) / 2].push_back(j);
  //         }
  //       }
  //     }
  //   }
  // }

  // for (int x : dp[i].size()) {
  // }
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "a.txt");
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
