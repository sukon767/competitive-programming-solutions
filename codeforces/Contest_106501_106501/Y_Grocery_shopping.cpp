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
 ________________________________________
( WHERE THE EVERLIVING HELL IS ERIC YANG )
 ----------------------------------------
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
  int n, m;
  cin >> n >> m;
  vector<ll> t(n);
  for (ll &i : t)
    cin >> i;
  vector<vector<ll>> v(n);
  while (m--) {
    int s, u;
    cin >> s >> u;
    v[s - 1].push_back(u);
  }
  vector<vector<ll>> dp1;
  int pt = 0;
  for (auto &a : v) {
    sort(a.begin(), a.end());
    vector<ll> dp(a.size());
    if (a.size() != 0)
      dp[0] = a[0] + t[pt];
    for (int i = 1; i < a.size(); i++)
      dp[i] = max(dp[i - 1], a[i]) + t[pt];
    dp1.push_back(dp);
    pt++;
  }
  vector<vector<ll>> dp(1 << n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < n; i++)
    dp[1 << i][i] = 0;
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1) {
        int pos = (int)(upper_bound(v[j].begin(), v[j].end(), dp[i][j]) -
                        v[j].begin()) -
                  1;
        dp[i][j] = max(dp[i][j], pos == -1 ? 0 : dp1[j][pos]) + t[j];
        for (int k = 0; k < n; k++)
          if (!((i >> k) & 1))
            dp[i ^ (1 << k)][k] = min(dp[i ^ (1 << k)][k], dp[i][j]);
      }
  }
  cout << *min_element(dp.back().begin(), dp.back().end()) << "\n";
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "y.txt");
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
