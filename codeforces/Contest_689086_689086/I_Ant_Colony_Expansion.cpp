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
 _______________
( tfw no cow gf )
 ---------------
        o   ^__^
         o  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/

const bool INTERACTIVE = true;
const bool MULTITEST = false;
/******************************************************************************/

#pragma region templates

#pragma endregion templates
pair<int, int> query(set<int> &x, vector<int> &y) {
  cout << "? " << x.size() << " ";
  for (int i : x)
    cout << i + 1 << " ";
  cout << y.size() << " ";
  for (int i : y)
    cout << i + 1 << " ";
  cout << endl;
  int a, b;
  cin >> a >> b;
  return {a == -1 ? -1 : a - 1, b == -1 ? -1 : b - 1};
}
void solve() {
  int n;
  cin >> n;
  int sq = sqrt(n);
  vector<set<int>> male((n - 1) / sq + 1);
  for (int i = 0; i < n; i++)
    male[i / sq].insert(i);
  vector<vector<int>> female((n - 1) / sq + 1);
  for (int i = 0; i < n; i++)
    female[i / sq].push_back(i);
  vector<int> ret(n, -1);
  for (auto &a : male) {
    for (int i = 0; i < female.size() && a.size(); i++)
      if (female[i].size()) {
        while (a.size()) {
          auto cur = query(a, female[i]);
          if (cur.first == -1)
            break;
          ret[cur.first] = cur.second;
          a.erase(cur.first);
        }
      }
  }
  cout << "! ";
  for (int i : ret)
    cout << (i == -1 ? -1 : i + 1) << " ";
  cout << endl;
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "i.txt");
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
