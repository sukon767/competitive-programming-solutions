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
const int MAXN = 1e7;
int pre[MAXN];
int p10[10];
int calc(int n) {
  if (n < MAXN && pre[n] != -1)
    return pre[n];

  string t = to_string(n);
  vector<int> pref(t.size()), suf(t.size());
  for (int i = 0; i < t.size(); i++)
    pref[i] = (i ? pref[i - 1] : 0) * 10 + t[i] - '0';
  for (int i = t.size() - 1; i >= 0; i--)
    suf[i] = (i == t.size() - 1 ? 0 : suf[i + 1]) +
             p10[t.size() - i - 1] * (t[i] - '0');
  int ans = n;
  for (int i = 1; i < (int)t.size(); i++)
    ans = min(ans, calc(pref[i - 1] + suf[i]));
  if (n < MAXN)
    pre[n] = ans;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  cout << calc(n) << '\n';
}

int main() {
  fill(pre, pre + MAXN, -1);
  for (int i = 0; i < 10; i++)
    pre[i] = i;
  p10[0] = 1;
  for (int i = 1; i < 10; i++)
    p10[i] = p10[i - 1] * 10;
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "b.txt");
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
