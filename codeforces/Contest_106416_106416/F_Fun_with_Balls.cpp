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
  v<int> k(n);
  cin >> k;

  auto solve = [&](int pos, v<v<int>> &cur, auto &&solve) -> int {
    if (pos == n) {
      queue<int2> nodes;
      v<v<bool>> vis;
      vis.reserve(cur.size());
      for (auto &x : cur)
        vis.emplace_back(x.size());

      auto bfs = [&]() {
        int sz = 0;
        while (nodes.size()) {
          auto [i, j] = nodes.front();
          nodes.pop();
          sz++;

          auto ck = [&](int u, int v) {
            if (u >= 0 && u < (int)cur.size() && v >= 0 && v < cur[u].size() &&
                !vis[u][v] && cur[u][v] == cur[i][j]) {
              vis[u][v] = 1;
              nodes.push({u, v});
            }
          };

          ck(i - 1, j);
          ck(i - 1, j + 1);

          ck(i, j + 1);
          ck(i, j - 1);

          ck(i + 1, j - 1);
          ck(i + 1, j);
        }
        return sz;
      };

      int ans = 0;
      for (int i = 0; i < (int)cur.size(); i++) {
        for (int j = 0; j < (int)cur[i].size(); j++) {
          if (!vis[i][j]) {
            nodes.push({i, j});
            vis[i][j] = 1;
            ans = max(ans, bfs());
          }
        }
      }

      return ans;
    }

    for (int i = (int)cur.size() - 1; i >= 0; i--) {
      if (cur[i].size() != (int)cur.size() - i) {
        cur[i].push_back(k[pos]);
        return solve(pos + 1, cur, solve);
      }
    }

    auto cura = cur;
    cura.push_back(v<int>{k[pos]});
    int ans = solve(pos + 1, cura, solve);

    cur.insert(cur.begin(), v<int>{k[pos]});
    ans = max(ans, solve(pos + 1, cur, solve));
    return ans;
  };

  auto x = v<v<int>>{{k[0]}};
  cout << solve(1, x, solve) << '\n';
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "f.txt");
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
