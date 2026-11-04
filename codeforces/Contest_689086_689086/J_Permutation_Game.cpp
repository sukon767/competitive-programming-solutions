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
 ________________________________________
( Why are you not doing Rutgers contest? )
(                                        )
( contest.rucp.org                       )
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
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  vector<bool> sa(n + 1), sb(n + 1);
  vector<ll> va, vb;

  for (int i = 1; i <= n; i++) {
    if (sa[i]) {
      continue;
    } else {
      // circ
      int cnt = 0, cur = i;

      while (!sa[cur]) {
        cnt++;
        sa[cur] = true;
        cur = a[cur];
      }
      va.push_back(cnt);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (sb[i]) {
      continue;
    } else {
      // circ
      int cnt = 0, cur = i;

      while (!sb[cur]) {
        cnt++;
        sb[cur] = true;
        cur = b[cur];
      }
      vb.push_back(cnt);
    }
  }

  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  vb.erase(unique(vb.begin(), vb.end()), vb.end());

  ll ans = 0;
  for (int i = 0; i < va.size(); i++) {
    ll cur = LLONG_MAX;
    for (int j = 0; j < vb.size(); j++) {
      cur = min(cur, lcm(va[i], vb[j]));
    }
    ans = max(ans, cur);
  }

  // for (int x : va)
  //   cout << x << " ";
  // cout << endl;
  // for (int x : vb)
  //   cout << x << " ";
  // cout << endl;

  cout << ans;
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "j.txt");
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
