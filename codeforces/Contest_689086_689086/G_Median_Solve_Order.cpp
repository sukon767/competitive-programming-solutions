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
const bool MULTITEST = true;
/******************************************************************************/

#pragma region templates

template <class T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using i128 = __int128;
ostream &operator<<(ostream &out, i128 x) {
  if (x == 0)
    return out << "0";
  string y = "";
  bool neg = x < 0;
  if (neg)
    x = -x;
  while (x) {
    y.push_back((char)(x % 10) + '0');
    x /= 10;
  }
  if (neg) {
    y.push_back('-');
  }
  reverse(all(y));
  return out << y;
}
i128 rng128() { return rng() | ((i128)rng() << 64); }
#pragma endregion templates

void solve() {
  int n;
  cin >> n;

  v<i128> fac(27, 1);
  for (int i = 1; i <= 26; i++) {
    fac[i] = fac[i - 1] * i;
  }

  set<char> chars;
  for (int i = 0; i < n; i++) {
    chars.insert('A' + i);
  }
  i128 targ = (fac[n] + 1) / 2;
  string ans;
  i128 cnt = 0;
  for (int i = 0; i < n; i++) {
    char cur;
    int j = 0;
    for (auto x : chars) {
      if (cnt + j * fac[n - i - 1] >= targ) {
        break;
      }
      cur = x;
      j++;
    }
    chars.erase(cur);
    ans.push_back(cur);
    cnt += (j - 1) * fac[n - i - 1];
  }

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
