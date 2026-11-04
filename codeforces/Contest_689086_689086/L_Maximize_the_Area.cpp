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
const bool MULTITEST = false;
/******************************************************************************/
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

#define f first
#define s second
#define bk back()
#define pb push_back

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

int N, Q;

const int MX = 2e5 + 5;

using T = long long; // or long long
const T EPS = 1e-9;  // might want to change
using P = pair<T, T>;
using vP = vector<P>;
using Line = pair<P, P>;

T sq(T a) { return a * a; }                      // square
T norm(const P &p) { return sq(p.f) + sq(p.s); } // x^2 + y^2

// basic operations
P operator-(const P &l, const P &r) { return P(l.f - r.f, l.s - r.s); }

T cross(const P &a, const P &b) {
  return a.f * b.s - a.s * b.f;
} // cross product
T cross(const P &p, const P &a, const P &b) { // cross product
  return cross(a - p, b - p);
}

using vi = vector<int>;
using vP = vector<P>;

vi hullInd(const vP &v) {
  int ind = int(min_element(all(v)) - begin(v));
  vi cand, hull{ind};
  F0R(i, sz(v)) if (v[i] != v[ind]) cand.pb(i);

  sort(all(cand), [&](int a, int b) { // sort by angle, tiebreak by distance
    P x = v[a] - v[ind], y = v[b] - v[ind];
    T t = cross(x, y);
    return t != 0 ? t > 0 : norm(x) < norm(y);
  });

  trav(c, cand) { // for every point
    while (sz(hull) > 1 && cross(v[end(hull)[-2]], v[hull.bk], v[c]) <= 0) {
      hull.pop_back(); // pop until counterclockwise and size > 1
    }
    hull.pb(c);
  }

  return hull;
}
#pragma region templates

#pragma endregion templates
#define a first
#define b second
ll area(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
  return abs(a.a * b.b + b.a * c.b + c.a * a.b -
             (a.b * b.a + b.b * c.a + c.b * a.a));
}
void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &a : v)
    cin >> a.a >> a.b;
  vector<int> pts = hullInd(v);
  vector<pair<pair<ll, ll>, int>> pt;
  for (int i : pts)
    pt.push_back({v[i], i});
  n = pt.size();
  if (n == 3) {
    sort(pts.begin(), pts.end());
    cout << "3\n";
    for (int i : pts)
      cout << i + 1 << " ";
    cout << "\n";
    return;
  }
  vector<int> best;
  ll ansA = 0;
  for (int i = 0; i < n; i++) {
    vector<int> left(n), right(n);
    vector<ll> leftArea(n), rightArea(n);
    int p = 1;
    for (int j = 2; j < n; j++) {
      while (p < j - 1 &&
             area(pt[i].a, pt[(i + p) % n].a, pt[(i + j) % n].a) <
                 area(pt[i].a, pt[(i + p + 1) % n].a, pt[(i + j) % n].a))
        p++;
      leftArea[j] = area(pt[i].a, pt[(i + p) % n].a, pt[(i + j) % n].a);
      left[j] = (i + p) % n;
    }
    p = 1;
    for (int j = 2; j < n; j++) {
      while (p < j - 1 &&
             area(pt[i].a, pt[(i - p + n) % n].a, pt[(i - j + n) % n].a) <
                 area(pt[i].a, pt[(i - p - 1 + 2 * n) % n].a,
                      pt[(i - j + n) % n].a))
        p++;
      rightArea[j] =
          area(pt[i].a, pt[(i - p + n) % n].a, pt[(i - j + n) % n].a);
      right[j] = (i - p + n) % n;
    }
    for (int j = 2; j < n - 1; j++) {
      ll cur = leftArea[j] + rightArea[n - j];
      if (cur > ansA) {
        ansA = cur;
        best = {pt[i].b, pt[left[j]].b, pt[(i + j) % n].b, pt[right[n - j]].b};
      }
    }
  }
  cout << "4\n";
  for (int i : best)
    cout << i + 1 << " ";
  cout << "\n";
}

int main() {
#ifdef DEV_MODE
  debug_start(INTERACTIVE, "l.txt");
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
