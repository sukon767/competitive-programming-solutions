#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <class T> T power(T a, long long e, T m) {
  for (T b = 1; ; (a *= a) %= m) {
    if (e & 1) (b *= a) %= m;
    if (!(e >>= 1)) return b;
  }
}

long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  if (a == 0) return b;
  if (b == 0) return a;
  const int s = __builtin_ctzll(a | b);
  a >>= __builtin_ctzll(a);
  do {
    b >>= __builtin_ctzll(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << s;
}

bool isPrime(long long n) {
  if (n <= 1 || n % 2 == 0) return (n == 2);
  const int s = __builtin_ctzll(n - 1);
  const long long d = (n - 1) >> s;
  // http://miller-rabin.appspot.com/
  for (const long long base : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    __int128 a = base % n;
    if (a == 0) continue;
    a = power<__int128>(a, d, n);
    if (a == 1 || a == n - 1) continue;
    bool ok = false;
    for (int i = 0; i < s - 1; ++i) {
      (a *= a) %= n;
      if (a == n - 1) {
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}

// n >= 3, odd
void factorizeRec(long long n, vector<long long> &ps) {
  static constexpr int BLOCK = 256;
  if (isPrime(n)) {
    ps.push_back(n);
  } else {
    for (long long c = 2; ; ++c) {
      long long x, y = 2, y0, z = 1, d = 1;
      for (int l = 1; d == 1; l <<= 1) {
        x = y;
        for (int i = 0; i < l; ++i) y = (static_cast<__int128>(y) * y + c) % n;
        for (int i = 0; i < l; i += BLOCK) {
          y0 = y;
          for (int j = 0; j < BLOCK && j < l - i; ++j) {
            y = (static_cast<__int128>(y) * y + c) % n;
            z = (static_cast<__int128>(z) * (y - x)) % n;
          }
          if ((d = gcd(z, n)) != 1) break;
        }
      }
      if (d == n) {
        for (y = y0; ; ) {
          y = (static_cast<__int128>(y) * y + c) % n;
          if ((d = gcd(y - x, n)) != 1) break;
        }
      }
      if (d != n) {
        factorizeRec(d, ps);
        factorizeRec(n / d, ps);
        return;
      }
    }
  }
}

vector<pair<long long, int>> factorize(long long n) {
  vector<pair<long long, int>> pes;
  if (n >= 2) {
    const int s = __builtin_ctzll(n);
    if (s) pes.emplace_back(2, s);
    if (n >> s >= 2) {
      vector<long long> ps;
      factorizeRec(n >> s, ps);
      std::sort(ps.begin(), ps.end());
      const int psLen = ps.size();
      for (int i = 0, j = 0; i < psLen; i = j) {
        for (; j < psLen && ps[i] == ps[j]; ++j) {}
        pes.emplace_back(ps[i], j - i);
      }
    }
  }
  return pes;
}

vector<long long> divisors(long long n) {
  const auto pes = factorize(n);
  vector<long long> ds{1};
  for (const auto &pe : pes) {
    const int len0 = ds.size();
    const int len1 = len0 * (pe.second + 1);
    ds.resize(len1);
    for (int i = len0; i < len1; ++i) ds[i] = ds[i - len0] * pe.first;
  }
  std::sort(ds.begin(), ds.end());
  return ds;
}

//sukon always reads the entire problem statement.
void solve() {
	ll S; int q; cin >> S >> q;
	vector<ll> d = divisors(S);
	vector<ll> pre(sz(d));
	for(int i = 0; i < sz(d); i++) {
		if(i) pre[i] += pre[i-1];
		pre[i] += S - (i ? S/d[i]*d[i-1] : 0);
	}

	while(q--) {
		ll ans = 0;
		ll x, y; cin >> x >> y;
		
		int lo = 0, hi = sz(d);
		//first occurence of < y.
		while(lo < hi) {
			int mid = (lo+hi)>>1;
			if(d[sz(d)-1-mid] < y) hi = mid;
			else lo = mid+1;
		}
		lo--;

		//flat
		ans += (lo>-1?min(x, d[lo]):0)*y;
		if(d[lo] >= x) {
			cout << ans << "\n"; continue;
		}

		int olo = lo;
		// cout << lo << endl;
		// cout << ans << endl;

		lo = 0, hi = sz(d);
		//first occurence of > x.
		while(lo < hi) {
			int mid = (lo+hi)>>1;
			if(d[mid] > x) hi = mid;
			else lo = mid+1;
		}

		//good
		olo = min(olo, lo-1);
		ans += (lo?pre[lo-1]:0)-(olo>-1?pre[olo]:0);
		// cout << olo << ' ' << lo << endl;

		// cout << ans << endl;
		// cout << lo << endl;
		//extra shit
		if(lo < sz(d)) ans += (x - (lo?d[lo-1]:0))*(d[sz(d)-1-lo]);

		cout << ans << "\n";
	}
}

//king of the sun o_O
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	//int t = 1;
	while(t--) {
		solve();
		if(t)   cout << "\n";
	}
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */