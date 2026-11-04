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
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  if (n == 1) {
    cout << "0\n";
    return;
  }
  if (n == 2) {
    if (a[0] == 1)
      cout << "0\n";
    else
      cout << "-1\n";
    return;
  }
  if (n == 3) {
    cout << "1\n3 1 2 3\n";
    return;
  }
  vector<vector<int>> ops;
  int x = n;
  while (x % 4 != 3) {
    if (a[x - 1] == x) {
      x--;
      continue;
    }
    int o = a[x - 1] ^ x;
    vector<int> inds;
    if ((1 << __lg(x)) == x && (o & x)) {
      int b = 1 << __lg(x);
      for (int i = 0; i < n; i++)
        if (i != x - 1 && a[i] != x && (a[i] & b)) {
          inds.push_back(i);
          o ^= a[i];
          break;
        }
    }
    if ((1 << __lg(a[x - 1])) == a[x - 1] && (o & a[x - 1])) {
      int b = 1 << __lg(a[x - 1]);
      for (int i = 0; i < n; i++)
        if (i != x - 1 && a[i] != x && (a[i] & b)) {
          inds.push_back(i);
          o ^= a[i];
          break;
        }
    }
    for (int i = 0; i < n; i++)
      if (((1 << __lg(a[i])) == a[i] && (o & a[i])) && i != x - 1 &&
          a[i] != x) {
        o ^= a[i];
        inds.push_back(i);
      }
    for (int i = 0; i < n; i++)
      if (a[i] == x)
        inds.push_back(i);
    inds.push_back(x - 1);
    sort(inds.begin(), inds.end());
    if (o != 0) {
      // cout << o << endl;
      // for (int i : a)
      //   cout << i << " ";
      // cout << endl;
      // for (int i : inds)
      //   cout << i + 1 << " ";
      // cout << endl;
      // assert((1 << __lg(n)) == n);
      cout << "-1\n";
      return;
    }
    // for (int i : inds)
    //   cout << i + 1 << " ";
    // cout << endl;
    vector<int> at(inds.size());
    for (int i = 0; i < at.size(); i++)
      at[i] = a[inds[i]];
    sort(at.begin(), at.end());
    for (int i = 0; i < at.size(); i++)
      a[inds[i]] = at[i];
    // for (int i : a)
    //   cout << i << " ";
    // cout << endl << endl;
    ops.push_back(inds);
    x--;
  }
  for (int i = x; i < n; i++)
    assert(a[i] == i + 1);
  cout << ops.size() + 1 << "\n";
  for (auto &a : ops) {
    cout << a.size() << " ";
    for (int i : a)
      cout << i + 1 << " ";
    cout << "\n";
  }
  cout << x << " ";
  for (int i = 1; i <= x; i++)
    cout << i << " ";
  cout << "\n";
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
