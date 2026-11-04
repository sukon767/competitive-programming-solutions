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
  string a;
  cin >> a;
  for (int i = 0; i <= 9; i++) {
    if (a.find('0' + i) == string::npos) {
      cout << i << '\n';
      return;
    }
  }
  for (auto &x : a)
    x -= '0';

  int n = a.size();

  auto dp = vec(n + 1, 10, 0);

  for (int j = 9; j >= 0; j--) {
    v<int> cnt(j + 1);
    int zero = j + 1;
    int r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (i == 0 && j == 0)
        break;
      if (a[i] <= j) {
        if (cnt[a[i]] == 0)
          zero--;
        cnt[a[i]]++;
      }

      if (zero && (i != 0 || cnt[0] != 0 || zero >= 2))
        continue;

      while (a[r] > j || cnt[a[r]] > 1 || (a[r] == 0 && i == 0)) {
        if (a[r] <= j)
          cnt[a[r]]--;
        r--;
      }
      dp[i][j] = dp[r + 1][9] + 1;
    }
  }

  int exp = dp[0][9];
  dbg(exp);
  dbg(dp[0]);

  string ans;
  int i = 0;
  while (i <= n) {
    int k = (i == 0) ? 1 : 0;
    dbg(dp[i]);
    while (k < 9 && dp[i][k] > exp) {
      k++;
    }
    dbg(i, k);
    ans.push_back(k + '0');

    if (exp == 0)
      break;
    while (a[i] != k) {
      dbg(i, (int)a[i], k);
      i++;
    }
    i++;
    exp--;
  }

  // for (int i = 0; i <= exp; i++)
  //   ans.push_back('0');

  cout << ans << '\n';
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "g.txt");
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
