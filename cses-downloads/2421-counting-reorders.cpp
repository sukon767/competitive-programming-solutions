#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
using str = string;      // yay python!
using vl = vector<ll>;
using vi = vector<int>;
#define tcT template <class T
#define tcTU tcT, class U
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;
// pairs
#define mp make_pair
#define f first
#define s second
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto &a : x)
// INPUT
#define tcTUU tcT, class... U
tcT > void re(T &x) { cin >> x; }
tcTUU > void re(T &t, U &...u) {
    re(t);
    re(u...);
}
tcT > void re(V<T> &x) { each(a, x) re(a); }
void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO() {
    unsyncIO();
    setPrec();
}
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef pair<int, int> pii;
/**
 * Author: Ludo Pulles, chilli, Simon Lindholm
 * Date: 2019-01-09
 * License: CC0
 * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf (do read, it's
 excellent) Accuracy bound from http://www.daemonology.net/papers/fft.pdf
 * Description: fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x /
 N)$ for all k$. N must be a power of 2. Useful for convolution:
   \texttt{conv(a, b) = c}, where c[x] = \sum a[i]b[x-i]$.
   For convolution of complex numbers or more than two vectors: FFT, multiply
   pointwise, divide by n, reverse(start+1, end), FFT back.
   Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$
   (in practice ^{16}$; higher for random inputs).
   Otherwise, use NTT/FFTMod.
 * Time: O(N \log N) with N = |A|+|B|$ ($\tilde 1s$ for N=2^{22}$)
 * Status: somewhat tested
 * Details: An in-depth examination of precision for both FFT and FFTMod can be
 found
 * here
 (https://github.com/simonlindholm/fft-precision/blob/master/fft-precision.md)
 */
typedef complex<double> C;
void fft(vector<C> &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
            // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  ///
            // include-line
            auto x = (double *)&rt[j + k],
                y = (double *)&a[i + j + k];  /// exclude-line
            C z(x[0] * y[0] - x[1] * y[1],
                x[0] * y[1] + x[1] * y[0]);  /// exclude-line
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
typedef vector<ll> vl;
template <int M> vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i, 0, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i, 0, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i, 0, n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i, 0, sz(res)) {
		ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
		ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}
const ll MOD = 1e9+7;
void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> cnt(26);
    for(char c : s) {
        cnt[c - 'a']++;
    }
    vector<ll> fac(n+1), in(n+1), ifac(n+1);
    fac[0] = ifac[0] = in[0] = in[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(i > 1) in[i] = (MOD-MOD/i)*in[MOD%i]%MOD;
        ifac[i] = ifac[i-1]*in[i]%MOD;
        fac[i] = fac[i-1]*i%MOD;
    }
    auto cmp = [](const auto& a, const auto& b) {
        return sz(a) > sz(b);
    };
    priority_queue<vector<ll>, vector<vector<ll>>, decltype(cmp)> pq(cmp);
    for(int i = 0; i < 26; i++) {
        if(!cnt[i]) continue;
        vector<ll> t(cnt[i]+1);
        for(int r = 1; r <= cnt[i]; r++){
            t[r] = (fac[cnt[i]-1]*ifac[r-1]%MOD*ifac[cnt[i]-r]%MOD)*ifac[r]%MOD*((cnt[i]-r)%2 ? MOD-1 : 1)%MOD;
        }
        pq.push(t);
    }
     while(sz(pq) > 1) {
        auto cur = std::move(const_cast<vector<ll>&>(pq.top()));
        pq.pop();
        auto cur2 = std::move(const_cast<vector<ll>&>(pq.top()));
        pq.pop();
        vector<ll> cur3 = convMod<1000000007>(cur, cur2);
        pq.push(cur3);
    }
    vector<ll> fin = std::move(const_cast<vector<ll>&>(pq.top()));
    ll ans = 0;
    for(int i = 0; i < sz(fin); i++) {
        ans += fin[i]*fac[i]%MOD; ans %= MOD;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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
 /* new testament
 * nick belov always reads the entire problem statement.
 */
