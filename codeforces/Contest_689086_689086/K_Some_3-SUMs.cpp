#include <bits/stdc++.h>
#include <random>
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
( She Gozinta on my Chain till i OEIS )
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
vector<int> ret;
void add(int a) {
  uniform_int_distribution<> d(1e7, 1e8);
  int r = d(rng);
  for (int i = 0; i < a; i++)
    ret.push_back(-r * 3);
  for (int i = 0; i < a; i++)
    ret.push_back(r * 2);
  for (int i = 0; i < a; i++)
    ret.push_back(r);
}
void solve() {
  ret.clear();
  int k;
  cin >> k;
  if (k == 0) {
    cout << "1\n1\n";
    return;
  }
  while (k > 0) {
    int lo = 0;
    while (lo * lo * lo <= k)
      lo++;
    lo--;
    add(lo);
    k -= lo * lo * lo;
  }
  cout << ret.size() << "\n";
  for (int i : ret)
    cout << i << " ";
  cout << "\n";
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "k.txt");
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
