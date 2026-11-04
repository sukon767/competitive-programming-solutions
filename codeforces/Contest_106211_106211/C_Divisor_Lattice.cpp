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

const bool INTERACTIVE = true;
const bool MULTITEST = false;
/******************************************************************************/

#pragma region templates

#pragma endregion templates

void solve() {
  int n;
  cin >> n;
  set<int> still;
  for (int i = 0; i < n; i++)
    still.insert(i + 1);
  // map<pair<int, int>, bool> done;

  // 1
  int one = 1;
  for (int x : still) {
    if (x == one)
      continue;
    cout << "? " << one << " " << x << endl << flush;

    int c;
    cin >> c;
    one = c;
  }

  still.erase(one);
  vector<int> ans;

  // ps

  while (still.size() > 1) {
    int cur = *still.begin();
    set<int> del;
    del.insert(cur);
    for (int x : still) {
      if (x == cur)
        continue;
      cout << "? " << cur << " " << x << endl << flush;
      int c;
      cin >> c;
      if (c == one)
        continue;
      del.insert(x);
      if (cur != c && cur != x)
        del.insert(c);
      cur = c;
    }

    for (int x : del)
      still.erase(x);
    ans.push_back(cur);
    // cout << still.size() << endl;
  }

  if (still.size())
    ans.push_back(*still.begin());

  cout << "! " << ans.size();
  for (int x : ans)
    cout << " " << x;
  cout << endl << flush;
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "c.txt");
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
