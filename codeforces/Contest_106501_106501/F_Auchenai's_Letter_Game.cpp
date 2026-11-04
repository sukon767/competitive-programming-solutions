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
 _____________________________________
( Life gives life to life, and that's )
( what the ICPC is about.             )
(                                     )
( - Bill Poucher                      )
 -------------------------------------
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
#define a first
#define b second
pair<ll, vector<pair<int, string>>> dothing(int I, int G, int M, ll IGM, ll GM,
                                            ll IM, int cnt) {
  ll ans = 0;
  vector<pair<int, string>> ret;
  ret.push_back({cnt, "IMGM"});
  I -= cnt;
  G -= cnt;
  M -= 2 * cnt;
  ans += cnt * (IM + GM);
  if (IGM + GM > IM) {
    int m = min(I, min(G, M));
    I -= m;
    G -= m;
    M -= m;
    ans += (IGM + GM) * m;
    ret.push_back({m, "IGM"});
  } else {
    int m = min(I, M);
    I -= m;
    M -= m;
    ans += IM * m;
    ret.push_back({m, "IM"});
  }
  if (IM > GM) {
    int m = min(I, M);
    I -= m;
    M -= m;
    ans += IM * m;
    ret.push_back({m, "IM"});
    m = min(G, M);
    G -= m;
    M -= m;
    ans += GM * m;
    ret.push_back({m, "GM"});
  } else {
    int m = min(G, M);
    G -= m;
    M -= m;
    ans += GM * m;
    ret.push_back({m, "GM"});
    m = min(I, M);
    I -= m;
    M -= m;
    ans += IM * m;
    ret.push_back({m, "IM"});
  }
  ret.push_back({I, "I"});
  ret.push_back({G, "G"});
  ret.push_back({M, "M"});
  return {ans, ret};
}
void solve() {
  int I, G, M;
  ll IGM, GM, IM;
  cin >> I >> G >> M >> IGM >> GM >> IM;
  pair<ll, vector<pair<int, string>>> ans = {-1, {}};
  for (int i = 0; i <= min(M / 2, min(I, G)); i++)
    ans = max(ans, dothing(I, G, M, IGM, GM, IM, i));
  cout << ans.a << "\n";
  for (auto &a : ans.b)
    while (a.a--)
      cout << a.b;
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
