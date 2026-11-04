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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> rm(n), sz(n);
  vector<bool> deld(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    g[--b].push_back(--a);
    sz[a]++;
  }
  vector<pair<int, int>> ret;
  function<bool(int)> dfs = [&](int x) {
    if (x == 0)
      return 0;
    deld[x] = 1;
    for (int i : g[x]) {
      if (!deld[i]) {
        if (rm[i] == sz[i] / 2) {
          if (!dfs(i))
            return 0;
        } else {
          ret.push_back({i, x});
          rm[i]++;
        }
      }
    }
    return 1;
  };
  if (!dfs(n - 1)) {
    cout << "-1\n";
    return;
  }
  cout << ret.size() << "\n";
  for (auto &a : ret)
    cout << a.first + 1 << " " << a.second + 1 << "\n";
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "h.txt");
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
